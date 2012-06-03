#include <QtCore/QString>
#include <QtTest/QtTest>
#include <QtCore>
#include <QtTest>
#include <D:/piu(QT)/zip.h>
#include <D:/piu(QT)/mainwindow.h>
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

    void testCase0();
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

void Test1Test::testCase0()
{
    QVERIFY2(true, "Failure");
}
void Test1Test::testCase1()
{
    bool alpha;
    zip piu;

    alpha =  piu.unzip("D:/piu(QT)/ClientHelp.chm");

    QVERIFY2(alpha, "Failure");

}
void Test1Test::testCase2()
{
    bool alpha;
    zip piu;

    alpha =  piu.zipdir("D:/piu(QT)/piu.htm");

    QVERIFY2(alpha, "Failure");

}

void Test1Test::testCase3()
{

    QLineEdit txt;
    QTest::keyClicks(&txt, "AKA");

   QCOMPARE(txt.text(), QString("AKA"));
    QVERIFY(txt.isModified());



}

void Test1Test::testCase4()
{
   QLineEdit lineEdit;
    QTest::keyClicks(&lineEdit, "piu");
    bool flag = false;
    QCOMPARE(flag,true);
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

    QLineEdit lineEdit;
     QTest::keyClicks(&lineEdit, "piupiupiu");
     bool flag = true;
     QCOMPARE(flag,true);

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

    QLineEdit lineEdit_2;
     QTest::keyClicks(&lineEdit_2, "blablabla");
     bool flag = true;
     QCOMPARE(flag,true);

}

void Test1Test::testCase11()

{

   MainWindow mw;
   bool flag = mw.setText();
   QCOMPARE(flag, true);

}




QTEST_MAIN(Test1Test)

#include "tst_test1test.moc"
