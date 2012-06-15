
#include "zip.h"

zip::zip()
{
}
bool zip::zipdir(QString dirname)
{
    QDir tempdir;
    tempdir.setPath(dirname);
    if (tempdir.exists())
    {
        QString program = "7z a -tzip 1.zip ./" + dirname + "/*";
        QProcess *zipProcess = new QProcess();
        zipProcess->start(program);
    }
    return true;
}
bool zip::unzip(QString filename)
{
    QFile zipfile;
    zipfile.setFileName(filename);
    if (zipfile.exists())
    {

        QString program = "./tmp/7z -y x -o./TEMP " +filename;
        QProcess *zipProcess = new QProcess();
        zipProcess->start(program);
        zipProcess->waitForFinished();

    }else
        return false;
    return true;
}

