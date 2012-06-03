#include <QtCore>
#ifndef ZIP_H
#define ZIP_H

class zip
{
public:
        zip();
        bool zipdir(QString dirname);
        bool unzip(QString filename);
    };

#endif // ZIP_H
