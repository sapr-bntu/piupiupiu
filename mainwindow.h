
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtDeclarative/QDeclarativeView>
#include <QGraphicsObject>
#include <QtGui>
#include <QDeclarativeContext>
#include <QDeclarativeEngine>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


    Q_INVOKABLE bool FunctionPIU();   //open and unzip
    Q_INVOKABLE bool FunctionPIUPIU();    //get files from root //string
    Q_INVOKABLE bool FunctionPIUPIUPIU();    //delete *.htm files
    Q_INVOKABLE bool FunctionMDE();    //open *.htm files   //string
    Q_INVOKABLE bool load(const QString &f);    //string
    Q_INVOKABLE void saveFile(const QString &fileName);  //save *.htm files
    Q_INVOKABLE void savik(const QString &piu1); //save
    Q_INVOKABLE QString FunctionOPEN(); // illustrate the first htm file on textedit  //string

     Q_INVOKABLE bool piupiuEx();
   Q_INVOKABLE bool maybeSave();
   Q_INVOKABLE bool fileNew();

  Q_INVOKABLE bool textFamily();
  Q_INVOKABLE  bool textSize();
    Q_INVOKABLE bool setText();





private:
    QDeclarativeView *ui;
    QObject *Root;//корневой элемент QML модели

private:


  QTextEdit *textEdit;
  //  QString load(const QString &f);
};

#endif // MAINWINDOW_H
