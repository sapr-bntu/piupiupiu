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
#include <QTextStream>
#include <ios>
#include <istream>
#include <ostream>
#include <QFSFileEngine>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{

    //�������� ��� QML


//    ui = new QDeclarativeView;
//    ui->setSource(QUrl("qrc:/main.qml"));
//    setCentralWidget(ui);
//    ui->setResizeMode(QDeclarativeView::SizeRootObjectToView);



//    //������� �������� �������
//    Root = ui->rootObject();
//    //��������� C++ � QML, ����� ������� ������� �++ ����� ������� window
//    ui->rootContext()->setContextProperty("window", this);




 //textEdit = new QTextEdit(this);

    setWindowTitle(tr("Html  Editor By Vegas/Brandy/Swer/Veres/SL v1.1"));

//    QFileSystemModel *model = new QFileSystemModel;
//    QString dir("../../");

//      QStringList piu ;
//      piu<<"*.htm";
//      model->setNameFilters(piu);
//      model->setFilter(QDir::AllEntries  );

//    model->setRootPath(dir);

//    ui->treeView->setModel(model);
//    ui->treeView->setRootIndex(model->index((dir)));
}

MainWindow::~MainWindow()
{
    //������� QML
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
    QString dir("../QML(Vegas)/");


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



QString MainWindow::FunctionOPEN()
{



//���������� ��� �����
//    QStringList filesList;
//        QString dir("C:\\tmp\\PiuLaba\\");
//      QDir directory = QDir(dir);
//      QStringList filters;
//      filters << "*.htm";
//      directory.setNameFilters(filters);
//      // Get the list of the png files inside Icons directory
//      filesList = directory.entryList(QDir::AllEntries);
//      // Generate random index of the element
//      int fileIdx = qrand() % filesList.count();

//      // Return file name
//      return filesList.at(fileIdx);

  //��������� ���� � �����
 //======================================================================
//   QString fileName = QFileDialog::getOpenFileName(this,
//            tr("Open"), "", tr("Files (*.txt *.htm *.xml *.chm)"));
//    QFile file(fileName);

//   // QFile file("piu.htm");
//   // file.open(QFile::WriteOnly);
//    // ��������� ����� � ����
//    //   file.close();
//    // �������� ���������� ���� � �����
//    QFileInfo info(file);
//   QString filepath = info.absoluteFilePath();
//   return filepath;
   //==================================================================================


//=====================================================================
//       QStringList filesList;
//       QString dir("D:\\PashaLab\\QML(Vegas)\\");
//       QDir directory = QDir(dir);
//       QStringList filters;
//       filters << "*.htm";
//       directory.setNameFilters(filters);
//       filesList = directory.entryList(QDir::AllEntries);


//    QByteArray list;
//// v skobah ukazat nomer elementa htm'ok 1,2,3..
//    QFile file(filesList[0]);



//      if (file.open(QIODevice::ReadOnly|QIODevice::Text))
//      {
//           QTextCodec *codec = Qt::codecForHtml(list);
//           QString str = codec->toUnicode(list);

//           list = file.readAll();
//      }

//return list;

//=============================================================================




    QStringList filesList;
   // QString dir("C:\\tmp\\PiuLaba\\");
    QString dir(".../QML(Vegas)/");
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

   if (file.open(QIODevice::ReadOnly|QIODevice::Text))
   {
        QTextCodec *codec = Qt::codecForHtml(list);
        QString str = codec->toUnicode(list);

        list = file.readAll();
   }

return list;
}





void MainWindow::FunctionPIU()
{

    QString fileName = QFileDialog::getOpenFileName(this,
            tr("Open"), "", tr("Files (*.txt *.htm *.xml *.chm)"));
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
                                              QString(), tr("Files (*.htm );;All Files (*)"));

  //  QString fn;
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
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save"), "", tr("Htm files (*.htm )"));
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



int MainWindow::kol(int n)
{
n++;
return n;
}

QString MainWindow::title(QString filePath)
{
    QFile file(filePath);
    file.open(QIODevice::ReadOnly);
    qint64 size = file.size();
    file.seek(size-125);
    QByteArray titleB = file.read(30);
    QString title(titleB);
    QByteArray artistB = file.read(30);
    QString artist(artistB);
    qDebug()<<artist+" "+title;
    return artist+" "+title;
}


QString MainWindow::WhereFile(QString filePath)
{
    QFile file(filePath);

//    QDir piudir("D:/107528/QT QML/PashaLab/QML(Vegas)/");
//    QStringList piuFiles = piudir.entryList(QDir::Files);
//    foreach (QString entry, piuFiles)
//                {
//                QString entryAbsPath = "D:/107528/QT QML/PashaLab/QML(Vegas)/";
//                }
    //QFile file(filePath);
   file.open(QIODevice::ReadOnly);
  //  file.remove();
  //  qint64 size = file.size();
   // file.seek(size-125);
  //  QByteArray titleB = file.readAll();
   // QString WhereFile(titleB);

    QTextStream stream(&file);
    QString str = stream.readAll();

    return str;

}

QString MainWindow::la(QString str)
{
   // QString filePath("../../");

    QFile file(str);
   // file.open(QIODevice::ReadOnly);
          if (!file.open (QIODevice::ReadOnly))
         qDebug()<<"Not open file";
    QTextStream stream ( &file );
    QString line;
    while( !stream.atEnd() ) {
         line = stream.readLine();//������ ������ �� �����
         line = stream.readAll();//��������� ���� ����
    }
    file.close();


    return line;

}


bool MainWindow::readFile(const QString &fileName)

 {

 QFile file(fileName);

 if (!file.open(QIODevice::ReadOnly)) {

 QMessageBox::warning(this, tr("Warning"),

 tr("Cannot read file %1:\n%2.")

 .arg(file.fileName())

 .arg(file.errorString()));

 return false;

 }

 QDataStream in(&file);

 in.setVersion(QDataStream::Qt_4_1);

 quint32 magic;

 in >> magic;


 quint16 row;

 quint16 column;

 QString str;

 QApplication::setOverrideCursor(Qt::WaitCursor);

 while (!in.atEnd()) {

 in >> row >> column >> str;


 }

 QApplication::restoreOverrideCursor();

 return true;

 }





