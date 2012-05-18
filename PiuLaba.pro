#-------------------------------------------------
#
# Project created by QtCreator 2012-05-09T20:56:05
#
#-------------------------------------------------

QT       += core gui declarative

symbian: {
    qmlfiles.sources = qml/qtquicktest/*.qml
    qmlfiles.path = ./qml/qtquicktest
    DEPLOYMENT += qmlfiles
}

TARGET = PiuLaba
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    zip.cpp

HEADERS  += mainwindow.h \
    zip.h

OTHER_FILES += \
    Controls/GreyButton.qml \
    Controls/RecipesModel.qml \
    Controls/TextButton.qml \
    main.qml \
    pics/lol5.jpg \
    pics/lol4.jpg \
    pics/lol3.jpg \
    pics/lol2.jpg \
    pics/lol1.jpg \
    pics/myicon.png \
    Controls/IconButtonD.qml \
    Controls/IconButtonU.qml \
    pics/up.PNG \
    pics/down.PNG \
    pics/sucks.png \
    pics/sucks.png \
    Controls/Scroll.qml \
    pics/scroll.png \
    pics/endHandle.sci \
    pics/startHandle.sci \
    pics/scrollbar.png

RESOURCES += \
    res.qrc
