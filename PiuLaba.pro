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
    Controls/TextArea.qml \
    Controls/TextButton.qml \
    main.qml \
    pics.txt \
    pics/plus-sign.png \
    pics/moreUp.png \
    pics/moreDown.png \
    pics/minus-sign.png \
    pics/lol5.jpg \
    pics/lol4.jpg \
    pics/lol3.jpg \
    pics/lol2.jpg \
    pics/lol1.jpg \
    pics/list-delete.png \
    pics/arrow-up.png \
    pics/arrow-down.png

RESOURCES += \
    res.qrc
