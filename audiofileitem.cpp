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
#include "audiofileitem.h"

AudioFileInfo::AudioFileInfo(const QString &tduringTime, const QString &tcreatedTime, int trank)
    : duringTime(tduringTime), createdTime(tcreatedTime), rank(QString::number(trank))
{
}

QString AudioFileInfo::getCreatedTime() const
{
    return createdTime;
}

QString AudioFileInfo::getDuringTime() const
{
    return duringTime;
}

QString AudioFileInfo::getRank() const
{
    return rank;
}

AudioFileInfoModel::AudioFileInfoModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

void AudioFileInfoModel::addAudioFileInfo(const AudioFileInfo &aFileInfo)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    fileInfoList << aFileInfo;
    endInsertRows();
}

int AudioFileInfoModel::rowCount(const QModelIndex & parent) const {
    Q_UNUSED(parent);
    return fileInfoList.count();
}

QVariant AudioFileInfoModel::data(const QModelIndex & index, int role) const {
    if (index.row() < 0 || index.row() >= fileInfoList.count())
        return QVariant();

    const AudioFileInfo &fileInfo = fileInfoList[index.row()];
    if (role == CreatedTimeRole)
        return fileInfo.getCreatedTime();
    else if (role == DuringTimeRole)
        return fileInfo.getDuringTime();
    else if (role == RankRole)
        return fileInfo.getRank();
    return QVariant();
}

//![0]
QHash<int, QByteArray> AudioFileInfoModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[DuringTimeRole] = "duringTime";
    roles[CreatedTimeRole] = "createdTime";
    roles[RankRole]="rank";
    return roles;
}
//![0]

