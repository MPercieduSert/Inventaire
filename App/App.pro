QT += widgets sql

CONFIG += c++17
CONFIG += link_prl
#CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../Compilation/libmps/entities/release/ -lentities
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../Compilation/libmps/entities/debug/ -lentities
else:unix: LIBS += -L$$PWD/../../../Compilation/libmps/entities/ -lentities

INCLUDEPATH += $$PWD/../../libmps/entities
DEPENDPATH += $$PWD/../../libmps/entities

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../Compilation/libmps/entities/release/libentities.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../Compilation/libmps/entities/debug/libentities.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../Compilation/libmps/entities/release/entities.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../Compilation/libmps/entities/debug/entities.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../../Compilation/libmps/entities/libentities.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../library/managerinv/release/ -lmanagerinv
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../library/managerinv/debug/ -lmanagerinv
else:unix: LIBS += -L$$OUT_PWD/../library/managerinv/ -lmanagerinv

INCLUDEPATH += $$PWD/../library/managerinv
DEPENDPATH += $$PWD/../library/managerinv

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../library/managerinv/release/libmanagerinv.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../library/managerinv/debug/libmanagerinv.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../library/managerinv/release/managerinv.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../library/managerinv/debug/managerinv.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../library/managerinv/libmanagerinv.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../library/feninv/release/ -lfeninv
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../library/feninv/debug/ -lfeninv
else:unix: LIBS += -L$$OUT_PWD/../library/feninv/ -lfeninv

INCLUDEPATH += $$PWD/../library/feninv
DEPENDPATH += $$PWD/../library/feninv

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../library/feninv/release/libfeninv.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../library/feninv/debug/libfeninv.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../library/feninv/release/feninv.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../library/feninv/debug/feninv.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../library/feninv/libfeninv.a

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../Compilation/libmps/manager/release/ -lmanager
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../Compilation/libmps/manager/debug/ -lmanager
else:unix: LIBS += -L$$PWD/../../../Compilation/libmps/manager/ -lmanager

INCLUDEPATH += $$PWD/../../libmps/manager
DEPENDPATH += $$PWD/../../libmps/manager

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../Compilation/libmps/manager/release/libmanager.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../Compilation/libmps/manager/debug/libmanager.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../Compilation/libmps/manager/release/manager.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../Compilation/libmps/manager/debug/manager.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../../Compilation/libmps/manager/libmanager.a

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../Compilation/libmps/widget/release/ -lwidget
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../Compilation/libmps/widget/debug/ -lwidget
else:unix: LIBS += -L$$PWD/../../../Compilation/libmps/widget/ -lwidget

INCLUDEPATH += $$PWD/../../libmps/widget
DEPENDPATH += $$PWD/../../libmps/widget

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../Compilation/libmps/widget/release/libwidget.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../Compilation/libmps/widget/debug/libwidget.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../Compilation/libmps/widget/release/widget.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../Compilation/libmps/widget/debug/widget.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../../Compilation/libmps/widget/libwidget.a

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../Compilation/libmps/fen/release/ -lfen
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../Compilation/libmps/fen/debug/ -lfen
else:unix: LIBS += -L$$PWD/../../../Compilation/libmps/fen/ -lfen

INCLUDEPATH += $$PWD/../../libmps/fen
DEPENDPATH += $$PWD/../../libmps/fen

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../Compilation/libmps/fen/release/libfen.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../Compilation/libmps/fen/debug/libfen.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../Compilation/libmps/fen/release/fen.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../Compilation/libmps/fen/debug/fen.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../../Compilation/libmps/fen/libfen.a
