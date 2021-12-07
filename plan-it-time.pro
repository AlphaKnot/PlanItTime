QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    OrbitalElements.cpp \
    Planets.cpp \
    alarmwidget.cpp \
    main.cpp \
    solarwidget.cpp \
    timewidget.cpp \
    uiscreen.cpp \


HEADERS += \
    OrbitalElements.h \
    Planets.h \
    alarmwidget.h \
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
    plan-it-time.pro.user \


RESOURCES += \
    resources.qrc

myImages.files = $$PWD/assets
myImages.path = Contents/Resources
myFont.files = $$PWD/fonts
myFont.path = Contents/Resources




