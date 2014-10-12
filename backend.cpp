#include "backend.h"


#include<QDebug>
Backend::Backend(QObject *parent) :
    QObject(parent)
{
    AFIM=new AudioFileInfoModel();
    AFIM->addAudioFileInfo(AudioFileInfo("Hello!","World!"));
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
    QDir dir("D:/sdcard/tencent/MicroMsg");
    QFileInfoList sdCardList=dir.entryInfoList(QDir::NoDotAndDotDot|QDir::Dirs);

    int index,len=0;
    for(int i=0;i<sdCardList.size();i++)
    {
        if(sdCardList[i].fileName().size()>len)
        {
            len=sdCardList[i].fileName().size();
            index=i;
        }
    }
    dir.setPath(dir.absolutePath()+"/"+sdCardList[index].fileName());
    sdCardList=dir.entryInfoList(QStringList("voice*"));
    for(int i=0;i<sdCardList.size();i++)
    {
        findFile(dir.absolutePath()+"/"+sdCardList[i].fileName());
    }
    qSort(resList.begin(),resList.end(),compare);


    for(int i=0;i<resList.size();i++)
    {
        qDebug()<<"!";
        AFIM->addAudioFileInfo(AudioFileInfo("Coming soon.",resList[i].created().toString().mid(3,14)));
    }
}
