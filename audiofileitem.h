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
#include <QAbstractListModel>
#include <QStringList>

class AudioFileInfo
{
public:
    AudioFileInfo(const QString &tduringTime, const QString &tcreatedTime, int trank);

    QString getDuringTime() const;
    QString getCreatedTime() const;
    QString getRank() const;

private:
    QString duringTime;
    QString createdTime;
    QString rank;
};

class AudioFileInfoModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum AudioFileInfoRoles {
        DuringTimeRole = Qt::UserRole + 1,
        CreatedTimeRole,
        RankRole
    };

    AudioFileInfoModel(QObject *parent = 0);

    void addAudioFileInfo(const AudioFileInfo &aFileInfo);

    int rowCount(const QModelIndex & parent = QModelIndex()) const;

    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

protected:
    QHash<int, QByteArray> roleNames() const;
private:
    QList<AudioFileInfo> fileInfoList;
};


