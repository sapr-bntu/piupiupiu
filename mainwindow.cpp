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
#include <QAction>
#include <QApplication>
#include <QClipboard>
#include <QColorDialog>
#include <QComboBox>
#include <QFontComboBox>
#include <QFile>
#include <QFileDialog>
#include <QFileInfo>
#include <QFontDatabase>
#include <QMenu>
#include <QMenuBar>
#include <QPrintDialog>
#include <QPrinter>
#include <QTextCodec>
#include <QTextEdit>
#include <QToolBar>
#include <QTextCursor>
#include <QTextDocumentWriter>
#include <QTextList>
#include <QtDebug>
#include <QCloseEvent>
#include <QMessageBox>
#include <QPrintPreviewDialog>
#include <QProcess>



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


bool MainWindow:: FunctionPIUPIU()
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
   // return piulist.join("|");
    return true;


}

bool MainWindow::FunctionPIUPIUPIU()
{


   // QString dir("D:/107528/piu(QML)+Button/");
    QString dir("C:/tmp/PiuLaba/");


    QStringList piu ;
    piu<<"*.htm";


 QDir piudir(dir);

         QStringList piulist;
           piulist = piudir.entryList(piu);

           for (int i = 0; i < piulist.size(); ++i)
  {
           QFile(piulist[i]).remove();
  }
return true;

}



QString MainWindow::FunctionOPEN()
{



//возвращаем имя файла
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

  //возращает путь к файлу
 //======================================================================
//   QString fileName = QFileDialog::getOpenFileName(this,
//            tr("Open"), "", tr("Files (*.txt *.htm *.xml *.chm)"));
//    QFile file(fileName);

//   // QFile file("piu.htm");
//   // file.open(QFile::WriteOnly);
//    // сохраняем даные в файл
//    //   file.close();
//    // получаем абсолютный путь к файлу
//    QFileInfo info(file);
//   QString filepath = info.absoluteFilePath();
//   return filepath;
   //==================================================================================


//=====================================================================
//       QStringList filesList;
//       QString dir("C:\\tmp\\PiuLaba\\");
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
   QString dir("../PiuLaba(Brandy)/");
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





bool MainWindow::FunctionPIU()
{

    QString fileName = QFileDialog::getOpenFileName(this,
            tr("Open"), "", tr("Files (*.txt *.htm *.xml *.chm)"));
    QFile file(fileName);

         if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
             return false;
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
        return true;



}

bool MainWindow::FunctionMDE()
{


    QString fn = QFileDialog::getOpenFileName(this, tr("Open File..."),
                                              QString(), tr("Files (*.htm );;All Files (*)"));

    QString text = "";
    if (!fn.isEmpty())
        return false;
      text = load(fn);
    return true;
}


bool MainWindow::load(const QString &f)
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

    return true;
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

bool MainWindow::piupiuEx()
{
    QApplication::exit();
    return true;

}

bool MainWindow::maybeSave()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save"), "", tr("Htm files (*.htm )"));
//    if (!textEdit->document()->isModified())
//        return true;
    if (fileName.startsWith(QLatin1String(":/")))
        return true;
    QMessageBox::StandardButton ret;
    ret = QMessageBox::warning(this, tr("Application"),
                               tr("The document has been modified.\n"
                                  "Do you want to save your changes?"),
                               QMessageBox::Save | QMessageBox::Discard
                               | QMessageBox::Cancel);
   // if (ret == QMessageBox::Save)
      //  return fileSave();
   // else if (ret == QMessageBox::Cancel)
    //    return false;
    return false;
}

bool MainWindow::fileNew()
{
    if (maybeSave()) {
        textEdit->clear();
               return true;
    }
    return false;
}



bool MainWindow::textFamily()
{
    QString f;
    QTextCharFormat fmt;
    fmt.setFontFamily(f);

    return true;
}

bool MainWindow::textSize()
{
    QString p;
    qreal pointSize = p.toFloat();
    if (p.toFloat() > 0) {
        QTextCharFormat fmt;
        fmt.setFontPointSize(pointSize);
        return true;
    }
    return false;
}

bool MainWindow::setText()
{
    bool ok;
    QString text = QInputDialog::getText(this, tr("Enter your label"),
                                         tr("Your label°:"), QLineEdit::Normal,
                                         QDir::home().dirName(), &ok);
    if (ok && !text.isEmpty())
       return true;
//     textLabel->setText();
    else return false;
}









