#include "qmlapplicationviewer.h"
#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QtDeclarative>
#include <QDeclarativeEngine>
#include <QTextCodec>
#include <QDirModel>
#include <QtDeclarative/QDeclarativeContext>


Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QScopedPointer<QApplication> app(createApplication(argc, argv));



//    QmlApplicationViewer viewer;
//    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
//    viewer.setMainQmlFile(QLatin1String("qml/QMLLab/main.qml"));
//    viewer.showExpanded();

 QTextCodec::setCodecForCStrings(QTextCodec::codecForName("Windows-1251"));
     QmlApplicationViewer viewer;
        QDirModel model;
      viewer.rootContext()->setContextProperty("dirModel", &model);
     viewer.rootContext()->setContextProperty("window", new MainWindow);
     viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
     viewer.setMainQmlFile(QLatin1String("qml/QMLLab/main.qml"));
     viewer.showExpanded();




    return app->exec();
}
