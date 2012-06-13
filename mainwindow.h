#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QtGui>
#include <QDirModel>
namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();







public:
      QString lineEditText;
       QSystemTrayIcon *trIcon;
    Ui::MainWindow *ui;

private slots:




public slots :
        bool open();
        bool exitMW();
       bool savik();
       bool clearik();
        bool delitik();
        void on_treeView_clicked(const QModelIndex &index);
        bool setText();
        bool about();
        bool aboutpiu();
        bool retStr();
        bool somethingWrong();
        bool ItsOk();
       bool clearView();
       bool clearEdit2();






public:

     bool  saveFile(const QString &fileName);


public:
    QDirModel* dirModel;
  //  QTreeView* treeView;
public:
    //QModelIndex index;
int currentIndex;

};


#endif // MAINWINDOW_H
