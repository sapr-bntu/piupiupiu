#include <QtCore/QString>
#include <QtTest/QtTest>
#include <QtCore>
#include <QtTest>
#include "../zip.h"
#include "../mainwindow.h"
#include <QtGui>
#include <QLineEdit>
#include <QtCore/QCoreApplication>
#include <QTextEdit>
#include <QFile>
#include <QDir>
#include <QFileDialog>
#include <QDirModel>


class Test1Test : public QObject
{
    Q_OBJECT
    
public:
    Test1Test();
    
private Q_SLOTS:
    void initTestCase();
    void testCase1();
    void testCase2();
    void testCase3();
    void testCase4();
    void testCase5();
    void testCase6();
    void testCase7();
    void testCase8();
    void testCase9();
    void testCase10();
    void testCase11();
    void testCase12();
    void testCase13();
    void testCase14();
    void testCase15();
    void cleanupTestCase();

};

Test1Test::Test1Test()
{
}
void Test1Test::initTestCase()
{
}

void Test1Test::cleanupTestCase()
{
}

void Test1Test::testCase1()
{
    bool alpha;
    zip piu;

    alpha =  piu.unzip("../ClientHelp.chm");

    QVERIFY2(alpha, "Failure");

}
void Test1Test::testCase2()
{
    bool alpha;
    zip piu;

    alpha =  piu.zipdir("../piu.htm");

    QVERIFY2(alpha, "Failure");

}

void Test1Test::testCase3()
{

MainWindow main;
bool flag = main.ItsOk();
QCOMPARE(flag, true);

}

void Test1Test::testCase4()
{
    MainWindow main;
    bool flag = main.somethingWrong();
    QCOMPARE(flag, true);
}


void Test1Test::testCase5()

{
    MainWindow mw;
     bool flag = mw.exitMW();
       QCOMPARE(true, flag);

}



void Test1Test::testCase6()

{

  MainWindow mw;
  bool flag = mw.clearik();
  QCOMPARE(true, flag);


}


void Test1Test::testCase7()

{
    MainWindow mw;
    bool flag = mw.retStr();
    QCOMPARE(true, flag);


}

void Test1Test::testCase8()

{

    MainWindow mw;
    bool flag = mw.aboutpiu();
    QCOMPARE(flag, true);


}


void Test1Test::testCase9()

{
MainWindow mw;
bool flag = mw.about();
QCOMPARE(flag, true);

}


void Test1Test::testCase10()

{
MainWindow mainw;
bool flag = mainw.clearView();
QCOMPARE(flag, true);

}

void Test1Test::testCase11()

{
    MainWindow mw;
    bool  flag = mw.saveFile("e:/1.htm");
      QCOMPARE(flag, true);

}


void Test1Test::testCase12()

{
    MainWindow mw;
     bool  flag = mw.savik();
      QCOMPARE(flag, true);


}


void Test1Test::testCase13()

{
 MainWindow mw;
  bool  flag = mw.open();
   QCOMPARE(flag, true);

}

void Test1Test::testCase14()

{

   MainWindow mw;
   bool flag = mw.clearEdit2();
   QCOMPARE(flag, true);

}
void Test1Test::testCase15()

{

   MainWindow mw;
   bool flag = mw.delitik();
   QCOMPARE(flag, true);

}


QTEST_MAIN(Test1Test)

#include "tst_test1test.moc"
