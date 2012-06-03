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
        void open();
        bool exitMW();
        void savik();
       bool clearik();
        void delitik();
        void on_treeView_clicked(const QModelIndex &index);
        bool setText();
        bool about();
        bool aboutpiu();




public:

     void saveFile(const QString &fileName);


public:
    QDirModel* dirModel;
  //  QTreeView* treeView;
public:
    //QModelIndex index;
int currentIndex;

};


#endif // MAINWINDOW_H
