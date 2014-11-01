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
#include "backend.h"


#include<QDebug>
Backend::Backend(QObject *parent) :
    QObject(parent)
{
    flag=false;
    ind=0;
    AFIM=new AudioFileInfoModel();
    //AFIM->addAudioFileInfo(AudioFileInfo("时长 ","创建日期",0));
    player=new QMediaPlayer();
    connect(player,SIGNAL(durationChanged(qint64)),this,SLOT(getDuration(qint64)),Qt::DirectConnection);
}

void Backend::findFile(QString path)
{
    QDir t(path);
    QFileInfoList fileName=t.entryInfoList(QDir::Files|QDir::NoDotAndDotDot);
    for(int i=0;i<fileName.size();i++)
    {
       resList.append(fileName[i]);
    }
    fileName=t.entryInfoList(QDir::Dirs|QDir::NoDotAndDotDot);
    for(int i=0;i<fileName.size();i++)
    {
        findFile(t.absolutePath()+"/"+fileName[i].fileName());
    }
    return;
}

inline bool compare(QFileInfo a,QFileInfo b)
{
    return a.created()>b.created();
}

void Backend::searchAudioFile()
{
    resList.clear();

    flag=false;
    QDir dir("/sdcard/tencent/MicroMsg");
    QFileInfoList firstLevel,sdCardList=dir.entryInfoList(QDir::NoDotAndDotDot|QDir::Dirs);

    int len=10;
    for(int i=0;i<sdCardList.size();i++)
    {
        if(sdCardList[i].fileName().size()>len)
        {
            firstLevel.append(sdCardList[i]);
        }
    }

    for(int j=0;j<firstLevel.size();j++)
    {
    dir.setPath(dir.absolutePath()+"/"+firstLevel[j].fileName());
    sdCardList=dir.entryInfoList(QStringList("voice*"));
    for(int i=0;i<sdCardList.size();i++)
    {
        findFile(dir.absolutePath()+"/"+sdCardList[i].fileName());
    }
    }
    qSort(resList.begin(),resList.end(),compare);

    reqDuration(ind);
}

void Backend::playSound(QString ind)
{
    flag=true;
    if(player->state()==QMediaPlayer::PlayingState)
    {
        player->stop();
    }
    else
    {
        player->setMedia(QUrl::fromLocalFile(resList[ind.toInt()-1].absoluteFilePath()));
        player->setVolume(100);
        player->play();
    }
}

void Backend::getDuration(qint64 d)
{
    if(flag==false && d!=0)
    {
        if((d/100)%10>=5)
            q.push_back(d/1000+1);
        else
            q.push_back(d/1000);
        ind++;
        reqDuration(ind);
    }
}

void Backend::reqDuration(int index)
{
    if(index>=resList.size())
    {
        addItems();
        return;
    }
    player->setMedia(QUrl::fromLocalFile(resList[index].absoluteFilePath()));
    player->duration();
    return;
}

void Backend::addItems()
{
    ind=0;
    while(!q.empty())
    {
        if(q.front()<10) t="0"+QString::number(q.front());
        else t=QString::number(q.front());
        q.pop_front();
        AFIM->addAudioFileInfo(AudioFileInfo(t+"秒",resList[ind].created().toString("MM月dd日 hh:mm:ss"),ind+1));
        ind++;
    }
}

void Backend::copyFile(QString ind)
{
    qDebug()<<"!!!";
    int index=ind.toInt()-1;
    QDir myDir("/sdcard/");
    if(!QDir(myDir.absolutePath()+"WeChatAudioManager").exists())
        myDir.mkdir("WeChatAudioManager");
    myDir.setPath("/sdcard/WeChatAudioManager/");

    QFile::copy(resList[index].absoluteFilePath(),myDir.absolutePath()+"/"+resList[index].fileName());
    //QMessageBox::information(0,"文件拷贝成功","当前语音消息已拷贝至"+myDir.absolutePath()+"中！请用文件管理器查看！",QMessageBox::Yes);
}

void Backend::slide(bool lor)
{
    qDebug()<<lor;
}
