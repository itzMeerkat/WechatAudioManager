/*
* Copyright 2013 AG3
*
* This file is part of WeChatAudioManager.
*
* WeChatAudioManager is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* WeChatAudioManager is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with WeChatAudioManager. If not, see <http://www.gnu.org/licenses/>.
*/
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
#include <QStringList>
#include <QFile>
#include <QDir>

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
    QStringList adList;
    QFile *adFile;
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
    QByteArray getAd();
};

#endif // BACKEND_H
