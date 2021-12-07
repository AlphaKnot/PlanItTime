QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += app_bundle
INCLUDEPATH += /opt/homebrew/Cellar/boost/1.76.0/include/

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Command.cpp \
    OrbitalElements.cpp \
    Planets.cpp \
    alarmwidget.cpp \
    asteroidwidget.cpp \
    linuxkbhit.cpp \
    main.cpp \
    solarwidget.cpp \
    timewidget.cpp \
    uiscreen.cpp \


HEADERS += \
    Command.h \
    OrbitalElements.h \
    Planets.h \
    alarmwidget.h \
    asteroidwidget.h \
    linuxkbhit.h \
    solarwidget.h \
    timewidget.h \
    uiscreen.h

FORMS += \
    uiscreen.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    README.md \
    alarm.wav \
    alarmTime.csv \
    dial.py \
    plan-it-time.pro.user \
    solarview.png


RESOURCES += \
    resources.qrc \
    resources.qrc

myImages.files = $$PWD/assets
myImages.path = Contents/Resources
myFont.files = $$PWD/fonts
myFont.path = Contents/Resources




