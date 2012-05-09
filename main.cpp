#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QtDeclarative>
#include <QDeclarativeEngine>
#include <QTextCodec>

#include "treemodel.h"

int main(int argc, char *argv[])
{

    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
      return a.exec();
}

