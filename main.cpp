#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QtDeclarative>
#include <QDeclarativeEngine>
#include <QTextCodec>

#include "treemodel.h"

int main(int argc, char *argv[])
{



    QApplication a(argc, argv);



    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("Windows-1251"));



    MainWindow w;
    w.show();
      return a.exec();
}

