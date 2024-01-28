QT       += core gui
QT       += svg
QT       += widgets svg
QT       += widgets


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aboutus.cpp \
    arrondissement.cpp \
    customwidget.cpp \
    departement.cpp \
    jo.cpp \
    main.cpp \
    mainwindow.cpp \
    mygraphicsscene.cpp \
    mypage.cpp \
    simul.cpp \
    zone.cpp

HEADERS += \
    aboutus.h \
    arrondissement.h \
    customwidget.h \
    departement.h \
    jo.h \
    mainwindow.h \
    mygraphicscene.h \
    mypage.h \
    simul.h \
    ui_arrondissementswindows.h \
    ui_zoneswindow.h \
    zone.h

FORMS += \
    aboutus.ui \
    arrondissement.ui \
    jo.ui \
    mainwindow.ui \
    simul.ui \
    ui_arrondissementswindow.ui \
    ui_zoneswindow.ui \
    zone.ui
    
TRANSLATIONS += Paris_en.ts \
                Paris_fr.ts \
                Paris_zh.ts \
                Paris_ar.ts \
                Paris_de.ts \
                Paris_es.ts


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES += \
    Paris_en.qm
