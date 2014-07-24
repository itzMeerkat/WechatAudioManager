#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDir>
#include<QFileInfo>
#include<QFileInfoList>
#include<QDateTime>
#include<QStandardItemModel>
#include<QFile>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_findFile_clicked();

    void on_copyFIle_clicked();

private:
    Ui::MainWindow *ui;
    QFileInfoList resList;
    QStandardItemModel *model = new QStandardItemModel;
    void findFile(QString path);
};

#endif // MAINWINDOW_H
