#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include "zip.h"
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


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


//  /*  trIcon = new QSystemTrayIcon();
//    trIcon->setIcon(QIcon("../piu.bmp"));
//    trIcon->setContextMenu(ui->menuFile);
//    trIcon->show()*/;

 //   connect(trIcon,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,SLOT(showHide(QSystemTrayIcon::ActivationReason)));

setWindowTitle(tr("Html  Editor By Vegas/Brandy/Swer/Veres/SL v1.1"));

       QFileSystemModel *model = new QFileSystemModel;
       QString dir("../piu(QT)/");



//filtr HTM- po4ti rabotaet(failu ne ubralis- oni v tumane:D).

         QStringList piu ;
         piu<<"*.htm";

         model->setNameFilters(piu);



//pokazivaet direktorii osnovnoi i po filtram-sostalnue blo4im
         //esli nado otkrit ostalnue papki- kommentim eto ->
       model->setFilter(QDir::AllEntries  );





       model->setRootPath(dir);
       ui->treeView->setModel(model);
       ui->treeView->setRootIndex(model->index((dir)));

       ui->treeView->show();
       ui->lineEdit->setText("piupiupiu");




    connect (ui->actionOpen, SIGNAL(triggered()), this , SLOT(open()));
   // connect (ui->actionUnzip, SIGNAL(triggered()),this, SLOT(buttonunzip()));
  //  connect (ui->actionZip,SIGNAL(triggered()),this,SLOT(buttonzip()));
    connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(savik()));
    connect(ui->actionExit, SIGNAL(triggered()),this, SLOT(exitMW()));
    connect(ui->actionDelete, SIGNAL(triggered()), this, SLOT(delitik()));
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(clearik()));
    connect(ui->actionAbout, SIGNAL(triggered()),this, SLOT(about()));
    connect(ui->actionAbout_project, SIGNAL(triggered()), this, SLOT(aboutpiu()));
    connect(ui->pushButton_2,SIGNAL(clicked()), this, SLOT(setText()));

    }

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::clearik()

{
ui->lineEdit->clear();


}

bool MainWindow::setText()
{
    bool ok;
    QString text = QInputDialog::getText(this, tr("Enter your label"),
                                         tr("Your label°:"), QLineEdit::Normal,
                                         QDir::home().dirName(), &ok);
    if (ok && !text.isEmpty())
        ui->lineEdit_2->setText(text);
//     textLabel->setText();
}



bool MainWindow::about()

{
    QMessageBox::about(this, tr("About Project"),
            tr("<p><b>CHM viewer v.1.0</p></b>"));
}


bool MainWindow::aboutpiu()
{QMessageBox::about(this, tr("About Coders"),
                    tr("<p> <b>CHM viewer v.1.0 </b> </p>"
                       "<p>-------------------------------</p>"
                       "<p><b>Coders:</p></b>"
                       "<p>Krivoruchko O.)</p>"
                       "<p>Khoruzhy P.</p>"
                       "<p>Mushenko V.</p>"
                       "<p>Krivorot D.</p>"
                          "<p>Gorevol V.</p>"

                       "<p>=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=</p>"
                       "<p><b>Project Manager:</p></b>"
                       "<p>Galko A.V.      ->g-ferz</p>"));




}



bool MainWindow::exitMW()
 {
    QApplication::exit();
    return true;
 }

void MainWindow::savik()
{
// save into 1.htm
//   QFile file("1.htm");
//    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
//             return;
//    QTextStream out(&file);
//    out<<ui->textEdit->toHtml();

 //save po viboru
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save"), "", tr("Files (*.htm )"));
        if (fileName.isEmpty())
            return;

        saveFile(fileName);
}

void MainWindow::delitik()

{



    QString dir("../piu(QT)/");


    QStringList piu ;
    piu<<"*.htm";


 QDir piudir(dir);

         QStringList piulist;
           piulist = piudir.entryList(piu);

           for (int i = 0; i < piulist.size(); ++i)
  {
           QFile(piulist[i]).remove();
  }





 }




 void MainWindow::saveFile(const QString &fileName)
{

     QFile file(fileName);


          if (!file.open(QFile::WriteOnly | QFile::Text)) {
              QMessageBox::warning(this, tr("Recent Files"),
                                   tr("Cannot write file %1:\n%2.")
                                   .arg(fileName)
                                   .arg(file.errorString()));
              return;
          }



          QTextStream out(&file);
          QApplication::setOverrideCursor(Qt::WaitCursor);
          out <<ui->textEdit->toHtml();
          QApplication::restoreOverrideCursor();

                 statusBar()->showMessage(tr("File saved"), 2000);


 }


void MainWindow::open()
{
 QString fileName = QFileDialog::getOpenFileName(this,
         tr("Open"), "", tr("Files (*.txt *.htm *.xml *.chm)"));
 QFile file(fileName);

      if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
          return;
      zip mzip;

      QDir dir(".");
      dir.mkdir("tmp");
      dir.cd("tmp");
      QFile f1;
      f1.copy(":/zip/7z.exe","./tmp/7z.exe");
      f1.copy(":/zip/7z.dll","./tmp/7z.dll");

      mzip.unzip(fileName);
     QTextStream in(&file);
     QString line = in.readAll();

ui->textEdit->setText(line);
}

void MainWindow::on_treeView_clicked(const QModelIndex &index)
{


qDebug()<<index.data().toString();

QFile file(index.data().toString());
    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug() <<  "Cannot open a file";
    }

    QTextStream in(&file);
QString str = in.readAll();
  ui->textEdit->setText(str);


}
