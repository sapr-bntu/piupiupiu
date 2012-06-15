#include <QtCore>
#include <QMainWindow>
#include <QtDeclarative/QDeclarativeView>
#include <QGraphicsObject>
#include <QtGui>
#include <QDeclarativeContext>
#ifndef ZIP_H
#define ZIP_H
//p

class zip
{
public:
        zip();
        bool zipdir(QString dirname);
        bool unzip(QString filename);

    };

#endif // ZIP_H
