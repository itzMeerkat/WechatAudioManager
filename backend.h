#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QDir>
#include <QFileInfo>
#include <QFileInfoList>
#include <QDateTime>
#include<audiofileitem.h>

class Backend : public QObject
{
    Q_OBJECT
public:
    //QAbstractListModel listModel;
    AudioFileInfoModel *AFIM;
    explicit Backend(QObject *parent = 0);

signals:

private:

    QFileInfoList resList;
    void findFile(QString);

public slots:
    void searchAudioFile();

};

#endif // BACKEND_H
