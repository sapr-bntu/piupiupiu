#include "qmlapplicationviewer.h"
#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QtDeclarative>
#include <QDeclarativeEngine>
#include <QTextCodec>
#include <QDirModel>
#include <QtDeclarative/QDeclarativeContext>
#include <QFileSystemModel>
#include <QTreeView>
#include <QTreeWidget>
#include <QDirModel>
#include <QListView>
#include <QSortFilterProxyModel>
#include <QDir>
#include <QFileDialog>
#include <QStringList>
#include "qfiledialog.h"
#include "qmessagebox.h"
#include <QString>
#include <QAction>
#include <QMenuBar>
#include <QMessageBox>
#include <QTextEdit>
#include <QDebug>
#include <QLineEdit>

Q_DECL_EXPORT int main(int argc, char *argv[])
{
     QScopedPointer<QApplication> app(createApplication(argc, argv));
     QTextCodec::setCodecForCStrings(QTextCodec::codecForName("Windows-1251"));
     QmlApplicationViewer viewer;
     QString dir("D://PashaLab//QML(Vegas)//");
     QStringList piu ;
     piu<<"*.htm";
     QDirModel model;
     viewer.rootContext()->setContextProperty("dirModel", &model);
     model.setFilter(QDir::AllEntries  | QDir::AllDirs) ;
     model.setNameFilters(piu);
     viewer.rootContext()->setContextProperty("window", new MainWindow);
     viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
     viewer.setMainQmlFile(QLatin1String("qml/QMLLab/main.qml"));
     viewer.showExpanded();
     return app->exec();
}
