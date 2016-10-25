#include <QCoreApplication>
#include <iostream>
#include <QFileInfo>
#include <QDateTime>
#include <QString>
#include <QDebug>
#include <QFileInfoList>
#include <QDir>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString path = "/tmp/";
    QFileInfoList entries = QDir(path).entryInfoList(QDir::AllEntries | QDir::System | QDir::NoDotAndDotDot | QDir::Hidden);

    QFileInfoList::const_iterator fi_entry;
    for (fi_entry = entries.constBegin(); fi_entry != entries.constEnd(); ++fi_entry)
    {
        QString relative_path = path + (*fi_entry).fileName();

        if ( fi_entry->isDir() )
        {
            qDebug() << "Directory : " << relative_path;
        }
        else
        {
            qDebug() << "File : " << relative_path;
        }
        qDebug() << "\t created  : " << QFileInfo(relative_path).created();
        qDebug() << "\t read     : " << QFileInfo(relative_path).lastRead();
        qDebug() << "\t modified : " << QFileInfo(relative_path).lastModified();
    }

    return a.exec();
}
