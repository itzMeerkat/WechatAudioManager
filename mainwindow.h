#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDir>
#include<QFile>
#include<QFileInfo>
#include<QFileInfoList>
#include<QLabel>
#include<QDateTime>
#include<algorithm>

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

private:
    Ui::MainWindow *ui;
    QStringList resList;
    void findFile(QString path);
};

#endif // MAINWINDOW_H
