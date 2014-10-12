#include "backend.h"


#include<QDebug>
Backend::Backend(QObject *parent) :
    QObject(parent)
{
    AFIM=new AudioFileInfoModel();
    AFIM->addAudioFileInfo(AudioFileInfo("Hello!","World!",0));
    player=new QMediaPlayer();
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


    for(int i=0;i<resList.size();i++)
    {
        //qDebug()<<"!";
        AFIM->addAudioFileInfo(AudioFileInfo("Coming soon.",resList[i].created().toString().mid(3,14),i+1));
    }
}

void Backend::playSound(QString ind)
{
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
    //qDebug()<<ind;
}
