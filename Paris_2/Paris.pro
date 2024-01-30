QT       += core gui
QT       += svg
QT       += widgets svg
QT       += widgets
QT 	 += core gui multimedia
QT 	 += multimediawidgets


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aboutus.cpp \
    activity.cpp \
    arrondissement.cpp \
    citymodel.cpp \
    coordinate.cpp \
    customwidget.cpp \
    departement.cpp \
    entity.cpp \
    jo.cpp \
    main.cpp \
    mainwindow.cpp \
    mygraphicsscene.cpp \
    mypage.cpp \
    person.cpp \
    place.cpp \
    secretgame.cpp \
    simul.cpp \
    zone.cpp

HEADERS += \
    aboutus.h \
    activity.h \
    arrondissement.h \
    citymodel.h \
    coordinate.h \
    customwidget.h \
    departement.h \
    entity.h \
    jo.h \
    mainwindow.h \
    mygraphicscene.h \
    mypage.h \
    person.h \
    place.h \
    secretgame.h \
    simul.h \
    zone.h

FORMS += \
    aboutus.ui \
    arrondissement.ui \
    jo.ui \
    mainwindow.ui \
    secretgame.ui \
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
