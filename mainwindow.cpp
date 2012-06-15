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
#include <QFile>
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

   // QString dir("D:\\107528\\piu(QML)+Button\\");


   QString dir("D:\\QTSDK\\piu(QML)+Button\\");

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
    QString dir("../PiuLaba/");
//        QString dir("E:/Study/PiuLaba/TEMP/ ");

    QStringList piu ;
    piu<<"*.htm";
    QDir piudir(dir);

//     int removeFolder(QDir & dir)
//     {

//            int res = 0;
//            //Получаем список каталогов
//            QStringList piuDirs  = piudir.entryList(QDir::Dirs  |
//                                          QDir::AllDirs |
//                                          QDir::NoDotAndDotDot);
//            //Получаем список файлов
//            QStringList piuFiles = piudir.entryList(QDir::Files);
//            //Удаляем файлы
//            foreach (QString entry, piuFiles)
//            {
//            QString entryAbsPath = "../PiuLaba/TEMP";
//            QFile::remove(entryAbsPath);
//            }
//            //Для папок делаем рекурсивный вызов
//            foreach (QString entry, piuDirs)
//            {
//            QString entryAbsPath = "../PiuLaba/TEMP";
//            removeFolder(QDir(entryAbsPath));
//            }
//            Удаляем обрабатываемую папку
//            //piudir.rmdir("../PiuLaba/TEMP");

//            if (!QDir().rmdir("../PiuLaba/TEMP"))
//            {

//            res = 1;
//            }
//            return res;
//     }

         QStringList piulist;
           piulist = piudir.entryList(piu);
           for (int i = 0; i < piulist.size(); ++i)
  {
           QFile(piulist[i]).remove();
  }


}



QString MainWindow::FunctionOPEN()
{


       QStringList filesList;
      // QString dir("C:\\tmp\\PiuLaba\\");
       QString dir("../PiuLaba/");
       QDir directory = QDir(dir);
       QStringList filters;
       filters << "*.htm";
       directory.setNameFilters(filters);
       filesList = directory.entryList(QDir::AllEntries);


    QByteArray list;
// v skobah ukazat nomer elementa htm'ok 1,2,3..
    QFile file(filesList[0]);


   // QFile file(filesList[i]);
     // QFile file("acl_con_use.htm");

//      if (file.open(QIODevice::ReadOnly|QIODevice::Text))
//      {
//           QTextCodec *codec = Qt::codecForHtml(list);
//           QString str = codec->toUnicode(list);

//           list = file.readAll();
//      }

return list;

}

void MainWindow::FunctionPIU()
{

    QString fileName = QFileDialog::getOpenFileName(this,
            tr("Open"), "", tr("chm files (*chm);;All Files (*)"));
    QFile file(fileName);

//         if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
//             return;
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
                                              QString(), tr("htm files (*.htm );;All Files (*)"));

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

 // QTextCodec *codec = Qt::codecForHtml(data);
 // QString str = codec->toUnicode(data);
QString str = data;

    return str;
}



void MainWindow::saveFile(const QString &fileName)
{

}

void MainWindow::savik(const QString &piu1)
{

 //save po viboru
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save as"), "", tr("htm files (*.htm )"));
        if (fileName.isEmpty())
            return;
        qDebug()<<"Save files:";
qDebug()<<piu1;
QFile file(fileName);


     if (!file.open(QFile::WriteOnly | QFile::Text)) {
         QMessageBox::warning(this, tr("Recent Files"),
                              tr("Cannot write file %1:\n%2.")
                              .arg(fileName)
                              .arg(file.errorString()));
         return;
     }



   //  QTextCodec *codec = Qt::codecForHtml();
   //  QString piu1 = codec->toUnicode();



     QTextStream out(&file);
     //out.setCodec(QTextCodec::codecForName("UTF-8"));

     QApplication::setOverrideCursor(Qt::WaitCursor);
   //  out <<ui->textEdit->toHtml();
   //   out.setCodec("UTF-8");



     out <<piu1;
     QApplication::restoreOverrideCursor();

            statusBar()->showMessage(tr("File saved"), 2000);


}

