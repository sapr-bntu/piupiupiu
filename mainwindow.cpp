#include "mainwindow.h"
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
#include <QDeclarativeEngine>
#include  <QDeclarativeView>
#include <QTextCodec>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{

    //Включаем наш QML
    ui = new QDeclarativeView;
    ui->setSource(QUrl("qrc:/main.qml"));
    setCentralWidget(ui);
    ui->setResizeMode(QDeclarativeView::SizeRootObjectToView);

    //Находим корневой элемент
    Root = ui->rootObject();
    //Соединяем C++ и QML, делая видимым функции С++ через элемент window


    ui->rootContext()->setContextProperty("window", this);


 //textEdit = new QTextEdit(this);

    setWindowTitle(tr("Html  Editor By Vegas/Brandy/Swer/Veres/SL v1.1"));
}

MainWindow::~MainWindow()
{
    //Удаляем QML
    delete ui;
}


QString MainWindow::FunctionPIUPIU()
{

   // QFileSystemModel *model = new QFileSystemModel;

    QString dir("D:\\107528\\piu(QML)+Button\\");

  //  QString dir("D:\\QTSDK\\piu(QML)+Button\\");

    QStringList piu ;
    piu<<"*.htm";


    QDir piudir(dir);
    QStringList piulist;
   // piulist<<"*.htm";

    piulist = piudir.entryList(piu);
    return piulist.join("|");


}

void MainWindow::FunctionPIUPIUPIU()
{


   // QString dir("D:/107528/piu(QML)+Button/");
    QString dir("C:/piu(QML)+Button/");


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

void MainWindow::FunctionPIU()
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

  // ui->textEdit->setText(line);

}

QString MainWindow::FunctionMDE()
{


    QString fn = QFileDialog::getOpenFileName(this, tr("Open File..."),
                                              QString(), tr("Files (*.htm );;All Files (*)"));

    QString text = "";
    if (!fn.isEmpty())
      text = load(fn);
    return text;
}


QString MainWindow::load(const QString &f)
{
    if (!QFile::exists(f))
        return false;
    QFile file(f);
    if (!file.open(QFile::ReadOnly))
        return false;

    QByteArray data = file.readAll();

    QTextCodec *codec = Qt::codecForHtml(data);
    QString str = codec->toUnicode(data);
    return str;
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
       //  out <<ui->textEdit->toHtml();
         out <<ui->window();
         QApplication::restoreOverrideCursor();

                statusBar()->showMessage(tr("File saved"), 2000);


}

void MainWindow::savik(const QString &piu1)
{
    qDebug()<<"piu1";
 //save po viboru
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save"), "", tr("Htm files (*.htm )"));
        if (fileName.isEmpty())
            return;
qDebug()<<piu1;
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
   //  out <<ui->textEdit->toHtml();
     out <<piu1;
     QApplication::restoreOverrideCursor();

            statusBar()->showMessage(tr("File saved"), 2000);


}

