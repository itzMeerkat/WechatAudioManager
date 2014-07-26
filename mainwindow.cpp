#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    model->setColumnCount(2);
    //model->setHeaderData(0,Qt::Horizontal,tr("文件名"));
    model->setHeaderData(0,Qt::Horizontal,tr("创建时间"));
    model->setHeaderData(1,Qt::Horizontal,tr("持续时间"));


    ui->tableView->setModel(model);
    ui->tableView->verticalHeader()->setVisible(true);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    playORpause=0;
    player=new QMediaPlayer;
    connect(player,SIGNAL(stateChanged(QMediaPlayer::State)),this,SLOT(changeButtonStatus(QMediaPlayer::State)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::findFile(QString path)
{
    qDebug()<<path;
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

bool com(QFileInfo a,QFileInfo b)
{
    return a.created()>b.created();
}

void MainWindow::on_findFile_clicked()
{
    //ui->listWidget->clear();
    QDir dir("/sdcard/tencent/MicroMsg");
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

    qSort(resList.begin(),resList.end(),com);
;

    for(int i=0;i<resList.size();i++)
    {
        QList<QStandardItem*> item;
        //QStandardItem* item2 = new QStandardItem(voiceList[i].fileName());
        QStandardItem* item3 = new QStandardItem(resList[i].created().toString().mid(3,14));
        QStandardItem* item4 = new QStandardItem("Comming Soon");
        item /*<< item2 */<< item3 << item4;
        model->appendRow(item);
    }
    ui->tableView->resizeColumnsToContents();
}

void MainWindow::on_copyFIle_clicked()
{
    QDir myDir("/sdcard/");
    if(!QDir(myDir.absolutePath()+"WeChatAudioManager").exists())
        myDir.mkdir("WeChatAudioManager");
    myDir.setPath("/sdcard/WeChatAudioManager/");

    int index=ui->tableView->currentIndex().row();
    qDebug()<<resList[index].absoluteFilePath();
    qDebug()<<myDir.absolutePath();
    QFile::copy(resList[index].absoluteFilePath(),myDir.absolutePath()+"/"+resList[index].fileName());
    QMessageBox::warning(this,"文件拷贝成功","当前语音消息已拷贝至"+myDir.absolutePath()+"中！请用文件管理器查看！");
}

void MainWindow::on_listen_clicked()
{
    if(player->state()==QMediaPlayer::StoppedState)
    {
        playORpause=0;
    }
    if(playORpause==1)
    {
        ui->listen->setText("试听");
        player->stop();
    }
    else
    {
        ui->listen->setText("停止");
        int index=ui->tableView->currentIndex().row();
        player->setMedia(QUrl::fromLocalFile(resList[index].absoluteFilePath()));
        player->setVolume(100);
        player->play();
    }
    playORpause=~playORpause;
    qDebug()<<playORpause;
}

void MainWindow::changeButtonStatus(QMediaPlayer::State s)
{
    if(s==QMediaPlayer::StoppedState)
    {
        ui->listen->setText("试听");
    }
}
