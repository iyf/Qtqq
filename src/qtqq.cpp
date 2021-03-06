#include "qtqq.h"

#include <QSettings>
#include <QMessageBox>

#include "loginwin.h"
#include "mainwindow.h"
#include "skinengine/qqskinengine.h"
#include "qq_protocol/qq_protocol.h"
#include "msgprocessor/msg_processor.h"
#include "chatwidget/chatmsg_processor.h"
#include "requestwidget/requestmsg_processor.h"
#include "chatwidget/chatdlg_manager.h"
#include "roster/roster.h"
#include "skinengine/qqskinengine.h"
#include "trayicon/systemtray.h"

Qtqq *Qtqq::instance_ = NULL;

Qtqq::Qtqq() : login_dlg_(NULL),
    main_win_(NULL)
{
	SystemTrayIcon * tray  = SystemTrayIcon::instance();

	minimize_ = new QAction(QIcon(QQSkinEngine::instance()->skinRes("systray_minimize")), tr("Minimize"), NULL);
	connect(minimize_, SIGNAL(triggered()), this, SLOT(onMinimize()));

	restore_ = new QAction(QIcon(QQSkinEngine::instance()->skinRes("systray_restore")), tr("Restore"), NULL);
	connect(restore_, SIGNAL(triggered()), this, SLOT(onRestore()));

	logout_ = new QAction(QIcon(QQSkinEngine::instance()->skinRes("systray_logout")), tr("Logout"), NULL);
	connect(logout_, SIGNAL(triggered()), this, SLOT(onLogout()));

	quit_ = new QAction(QIcon(QQSkinEngine::instance()->skinRes("systray_quit")), tr("Quit"), NULL);
	connect(quit_, SIGNAL(triggered()), this, SLOT(onQuit()));

	tray->addMenuAction(minimize_);
	tray->addMenuAction(minimize_);
	tray->addMenuAction(restore_);
	tray->addMenuAction(logout_);
	tray->addMenuAction(quit_);
	tray->addSeparator();
}

Qtqq::~Qtqq()
{
    if (login_dlg_)
    {
        login_dlg_->close();
        login_dlg_->deleteLater();
    }
    if (main_win_)
    {
    main_win_->close();
    main_win_->deleteLater();
    }
}

void Qtqq::start()
{
    login_dlg_ = new LoginWin();
    connect(login_dlg_, SIGNAL(sig_loginFinish()), this, SLOT(showMainPanel()));
}

void Qtqq::showMainPanel()
{
	//instantiate them
	Protocol::QQProtocol::instance();
	MsgProcessor::instance();
	ChatMsgProcessor::instance();
	RequestMsgProcessor::instance();
	StrangerManager::instance();
	
	main_win_ = new MainWindow();
	main_win_->initialize();
    main_win_->show();
	main_win_->updateLoginUser();

    login_dlg_->deleteLater();
    login_dlg_ = NULL;

	SystemTrayIcon *trayicon = SystemTrayIcon::instance();
	trayicon->show();
}

void Qtqq::onMinimize()
{
    main_win_->hide();
}

void Qtqq::onRestore()
{
    main_win_->showNormal();
}

void Qtqq::onLogout()
{
	Protocol::QQProtocol::instance()->stop();
	MsgProcessor::instance()->stop();
	ChatMsgProcessor::instance()->stop();
	RequestMsgProcessor::instance()->stop();

	delete StrangerManager::instance();
	delete ChatDlgManager::instance();
	delete Roster::instance();
    delete main_win_;

	SystemTrayIcon *trayicon = SystemTrayIcon::instance();
	trayicon->hide();

    start();
}

void Qtqq::onQuit()
{
	delete Protocol::QQProtocol::instance();
	delete MsgProcessor::instance();
	delete ChatMsgProcessor::instance();
	delete RequestMsgProcessor::instance();
	delete StrangerManager::instance();
	delete ChatDlgManager::instance();
	delete Roster::instance();

	if ( main_win_ )
		delete main_win_;
	main_win_ = NULL;

	delete minimize_;
	minimize_ = NULL;

	delete restore_;
	restore_ = NULL;

	delete logout_;
	logout_ = NULL;

	delete quit_;
	quit_ = NULL;

	qApp->quit();
}
