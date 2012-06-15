
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtDeclarative/QDeclarativeView>
#include <QGraphicsObject>
#include <QtGui>
#include <QDeclarativeContext>
#include <QDeclarativeEngine>
#include <QFileSystemModel>
#include <QTreeView>
#include <QTreeWidget>
#include <QDirModel>
#include <QListView>
#include <QSortFilterProxyModel>
#include <QDir>
#include <QFileDialog>
#include <QStringList>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


    Q_INVOKABLE void FunctionPIU();   //open and unzip
    Q_INVOKABLE QString FunctionPIUPIU();    //get files from root
    Q_INVOKABLE void FunctionPIUPIUPIU();    //delete *.htm files
    Q_INVOKABLE QString FunctionMDE();    //open *.htm files
    Q_INVOKABLE QString load(const QString &f);
    Q_INVOKABLE void saveFile(const QString &fileName);  //save *.htm files
    Q_INVOKABLE void savik(const QString &piu1); //save
    Q_INVOKABLE QString FunctionOPEN(); // illustrate the first htm file on textedit
    Q_INVOKABLE  QString title(QString filePath);
    Q_INVOKABLE QString WhereFile(QString filePath);
    Q_INVOKABLE QString la(QString str);
   Q_INVOKABLE  bool readFile(const QString &fileName);


public slots:
     int kol(int n);


private:
    QDeclarativeView *ui;
    QObject *Root;//корневой элемент QML модели

private:


  QTextEdit *textEdit;
  //  QString load(const QString &f);
};

#endif // MAINWINDOW_H
