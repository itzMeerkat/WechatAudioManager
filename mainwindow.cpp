#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::findFile(QString path)
{
    qDebug()<<path;
    QDir t(path);
    QStringList fileName=t.entryList(QDir::Files | QDir::NoDotAndDotDot);
    for(int i=0;i<fileName.size();i++)
    {
        resList.append(fileName[i]);
    }
    fileName=t.entryList(QDir::Dirs|QDir::NoDotAndDotDot);
    for(int i=0;i<fileName.size();i++)
    {
        findFile(t.absolutePath()+"/"+fileName[i]);
    }
    return;
}

bool com(QFileInfo a,QFileInfo b)
{
    return a.created()<b.created();
}

void MainWindow::on_findFile_clicked()
{
    ui->listWidget->clear();
    QDir dir("/sdcard/tencent/MicroMsg");
    QStringList sdCardList=dir.entryList();
    QFileInfoList voiceList;
    QFileInfo temp;
    int index,len=0;
    for(int i=0;i<sdCardList.size();i++)
    {
        if(sdCardList[i].size()>len)
        {
            len=sdCardList[i].size();
            index=i;
        }
    }
    dir.setPath(dir.absolutePath()+"/"+sdCardList[index]);
    sdCardList=dir.entryList(QStringList("voice*"));

    for(int i=0;i<sdCardList.size();i++)
    {
        findFile(dir.absolutePath()+"/"+sdCardList[i]);
    }

    for(int i=0;i<resList.size();i++)
    {
        temp.setFile(dir,resList[i]);
        voiceList.append(temp);
    }

    qSort(voiceList.begin(),voiceList.end(),com);

    for(int i=0;i<voiceList.size();i++)
    {
        qDebug()<<voiceList.at(i).created().isValid();
        ui->listWidget->addItem(voiceList[i].created().toString());
    }
    //ui->listWidget->addItems(resList);
}
