#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDir>
#include<QFileInfo>
#include<QFileInfoList>
#include<QDateTime>
#include<QStandardItemModel>
#include<QMessageBox>
#include<QMediaPlayer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    QMediaPlayer *player;
    ~MainWindow();

private slots:
    void on_findFile_clicked();

    void on_copyFIle_clicked();

    void on_listen_clicked();

    void changeButtonStatus(QMediaPlayer::State);

private:
    Ui::MainWindow *ui;
    QFileInfoList resList;
    QStandardItemModel *model = new QStandardItemModel;
    bool playORpause;//play for 0, pause for 1

    void findFile(QString path);
};

#endif // MAINWINDOW_H
