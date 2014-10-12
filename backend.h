#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QDir>
#include <QFileInfo>
#include <QFileInfoList>
#include <QDateTime>
#include <audiofileitem.h>
#include <QMediaPlayer>

class Backend : public QObject
{
    Q_OBJECT
public:
    //QAbstractListModel listModel;
    AudioFileInfoModel *AFIM;
    explicit Backend(QObject *parent = 0);

signals:

private:
    QMediaPlayer *player;
    QFileInfoList resList;
    void findFile(QString);

public slots:
    void searchAudioFile();
    void playSound(QString ind);

};

#endif // BACKEND_H
