set(CORE_HEADERS
	core/qqlogincore.h
	core/qqmsglistener.h
	core/groupchatlog.h
	core/friendchatlog.h
	core/request.h
	core/msgsender.h
	core/types.h
	core/qqavatarrequester.h
	core/groupimgloader.h
	core/qqmsg.h
	core/nameconvertor.h
	core/groupimgsender.h
	core/qqskinable.h
	core/qqchatlog.h
	core/imgsender.h
	core/accountmanager.h
	core/qqitem.h
	core/friendimgsender.h
	core/sockethelper.h
	core/qqchatitem.h
	core/imgloader.h
	core/captchainfo.h
	core/qqutility.h
    core/singleton.h
    core/tasks.h
	core/talkable.h
	core/curr_login_account.h

	#chat widget
	chatwidget/tabwindow.h
	chatwidget/qqchatdlg.h
	chatwidget/friendchatdlg.h
	chatwidget/groupchatdlg.h
	chatwidget/sesschatdlg.h
	chatwidget/chatmsg_processor.h
	chatwidget/chatdlg_manager.h

	#request widget
	requestwidget/grouprequestdlg.h
	requestwidget/friendrequestdlg.h
	requestwidget/requestmsg_processor.h

	#msgprocessor
	msgprocessor/msg_processor.h

	#qq_protocol
	qq_protocol/qq_protocol.h
	qq_protocol/pollthread.h

	#request_jobs
	qq_protocol/request_jobs/job_base.h
	qq_protocol/request_jobs/friendinfo2_job.h
	qq_protocol/request_jobs/strangerinfo2_job.h
	qq_protocol/request_jobs/icon_job.h

	#roster
	roster/roster.h

	#roster model
	rostermodel/roster_model_base.h
	rostermodel/roster_index.h
	rostermodel/roster_model.h
	rostermodel/recent_model.h
	rostermodel/contact_proxy_model.h

	#skinengine
	skinengine/qqskinengine.h
	skinengine/msgstyle_manager.h

	#sound player
	soundplayer/soundplayer.h

	#storage
	storage/storage.h

	#strangermanager
	strangermanager/stranger_manager.h

	#utils
	utils/request_callback.h
	utils/contact_status.h
	utils/icon_decorator.h

	#trayicon
	trayicon/systemtray.h
)

set(UI_HEADERS
	chatlogwin.h
	frienditem.h
	qtqq.h
	frienditemmodel.h
	qqtextedit.h
	moveablehandler.h
	qqtitlebar.h
	recentlistitemmodel.h
	groupitemmodel.h
	msgbrowse.h
	mainwindow.h
	loginwin.h
	qqfacepanel.h
	qqiteminfohelper.h
	qqwidget.h
	qqitemmodel.h
	friendinfodlg.h
    qqglobal.h
    friendsearcher.h
    friendsearchlineedit.h
)

QT4_WRAP_CPP(UI_HEADERS_MOC ${UI_HEADERS})
QT4_WRAP_CPP(CORE_HEADERS_MOC ${CORE_HEADERS})

set(CORE_SOURCES
	core/qqlogincore.cpp
	core/friendimgsender.cpp
	core/qqchatitem.cpp
	core/groupchatlog.cpp
	core/qqavatarrequester.cpp
	core/imgloader.cpp
	core/types.cpp
	core/groupimgsender.cpp
	core/sockethelper.cpp
	core/captchainfo.cpp
	#core/qqsetting.cpp
	core/groupimgloader.cpp
	core/msgsender.cpp
	core/qqitem.cpp
	core/friendchatlog.cpp
	core/qqchatlog.cpp
	core/request.cpp
	core/imgsender.cpp
	core/qqutility.cpp
	core/accountmanager.cpp
	core/qqmsg.cpp
	#core/msgcenter.cpp
	#core/uncheckmsg_notifier.cpp
	core/curr_login_account.cpp


	#msgprocessor
	msgprocessor/msg_processor.cpp

	#qq_protocol
	qq_protocol/qq_protocol.cpp
	qq_protocol/pollthread.cpp

	#request_jobs
	qq_protocol/request_jobs/job_base.cpp
	qq_protocol/request_jobs/icon_job.cpp
	qq_protocol/request_jobs/friendinfo2_job.cpp
	qq_protocol/request_jobs/strangerinfo2_job.cpp

	#roster
	roster/roster.cpp

	#roster model
	rostermodel/roster_model_base.cpp
	rostermodel/recent_model.cpp
	rostermodel/roster_index.cpp
	rostermodel/roster_model.cpp
	rostermodel/contact_proxy_model.cpp

	#skinengine
	skinengine/qqskinengine.cpp
	skinengine/msgstyle_manager.cpp

	#sound player
	soundplayer/soundplayer.cpp

	#storage
	storage/storage.cpp

	#strangermanager
	strangermanager/stranger_manager.cpp

	#utils
	utils/request_callback.cpp
	utils/icon_decorator.cpp

	#chat widget
	chatwidget/tabwindow.cpp
	chatwidget/friendchatdlg.cpp
	chatwidget/groupchatdlg.cpp
	chatwidget/qqchatdlg.cpp
	chatwidget/sesschatdlg.cpp
	chatwidget/chatmsg_processor.cpp
	chatwidget/chatdlg_manager.cpp

	#request widget
	requestwidget/grouprequestdlg.cpp
	requestwidget/friendrequestdlg.cpp
	requestwidget/requestmsg_processor.cpp

	#trayicon
	trayicon/systemtray.cpp
)

set(UI_SOURCES
	main.cpp
	qqtitlebar.cpp
	qtqq.cpp
	chatlogwin.cpp
	moveablehandler.cpp
	friendinfodlg.cpp
	qqitemmodel.cpp
	msgbrowse.cpp
	qqwidget.cpp
	mainwindow.cpp
	qqtextedit.cpp
	qqfacepanel.cpp
	recentlistitemmodel.cpp
	frienditemmodel.cpp
	loginwin.cpp
	groupitemmodel.cpp
	qqiteminfohelper.cpp
    qqglobal.cpp
    friendsearcher.cpp
    friendsearchlineedit.cpp
)

set(UI_FILES
	ui/captcha.ui
	ui/friendinfodlg.ui
	ui/loginwin.ui
	ui/chatlogwin.ui
	ui/friendrequestdlg.ui
	ui/mainwindow.ui
	ui/groupchatdlg.ui
	ui/friendchatdlg.ui
	ui/grouprequestdlg.ui
	ui/qqfacepanel.ui
	ui/sesschatdlg.ui
	ui/tabwindow.ui
)

QT4_WRAP_UI(UI_FILES_HEADERS ${UI_FILES})

PKG_CHECK_MODULES(ZLIB REQUIRED "zlib")

set(QT_USE_QTNETWORK TRUE)
set(QT_USE_QTWEBKIT TRUE)
set(QT_USE_QTSQL TRUE)
set(QT_USE_QTXML TRUE)

include(${QT_USE_FILE})

include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${JSONCPP_INCLUDE_DIR})
include_directories(${LOG4QT_INCLUDE_DIR})
include_directories(${QXGS_INCLUDE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_definitions(${QT_DEFINITIONS})

#set(lang_SOURCES
#	${CORE_SOURCES}
#	${UI_SOURCES}
#	${UI_FILES_HEADERS}
#)

#set(TRANSLATIONS_FILES ${TRANSLATIONS_DIR}/qtqq_zh.ts)
set(TRANSLATIONS_FILE ${TRANSLATIONS_DIR}/qtqq_zh.qm)

# TURN ON UPDATE_TRANSLATIONS will delete all the *.ts files
# BE CAREFUL!
option(UPDATE_TRANSLATIONS "Update source translation files" OFF)

#if (UPDATE_TRANSLATIONS)
#	QT4_CREATE_TRANSLATION(QM_FILES ${lang_SOURCES} ${TRANSLATIONS_FILES})
#else (UPDATE_TRANSLATIONS)
#	QT4_ADD_TRANSLATION(QM_FILES ${TRANSLATIONS_FILES})
#endif (UPDATE_TRANSLATIONS)

add_executable(qtqq
	${CORE_SOURCES} ${CORE_HEADERS_MOC}
	${UI_SOURCES} ${UI_HEADERS_MOC}
	${UI_FILES_HEADERS}
	${QM_FILES}
)

target_link_libraries(qtqq
	log4qt
	qxtglobalshortcut
	jsoncxx
	${QT_LIBRARIES}
	${ZLIB_LIBRARIES}
)

install(TARGETS qtqq DESTINATION ${prefix}/bin)
#install(FILES ${QM_FILES} DESTINATION ${pkgdatadir}/translations)
install(FILES ${TRANSLATIONS_FILE} DESTINATION ${pkgdatadir}/translations)
