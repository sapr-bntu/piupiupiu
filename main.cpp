#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QtGui>
#include <QTextCodec>

int main(int argc, char *argv[])
{

   QApplication a(argc, argv);

    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

    MainWindow *w=new MainWindow;

    w->show();



    return a.exec();
}
