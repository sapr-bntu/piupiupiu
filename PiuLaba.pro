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
    main.qml

RESOURCES += \
    res.qrc
