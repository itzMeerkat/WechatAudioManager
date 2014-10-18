#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QDir>
#include <QFileInfo>
#include <QFileInfoList>
#include <QDateTime>
#include <audiofileitem.h>
#include <QMediaPlayer>
#include <QQueue>
#include <QMessageBox>

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
    bool flag;
    QQueue<int> q;
    QString t;
    int ind;
    void addItems();
    void reqDuration(int);

public slots:
    void searchAudioFile();
    void playSound(QString ind);
    void getDuration(qint64);
    void copyFile(QString);
    void slide(bool);
};

#endif // BACKEND_H
