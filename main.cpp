#include<backend.h>
#include <QApplication>

#include<QDesktopWidget>
#include<QQuickView>
#include<QQmlContext>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Backend bkend;
    QRect screen=QApplication::desktop()->screenGeometry();
    QQuickView *mainView=new QQuickView();
    QQmlContext *context=mainView->rootContext();
    context->setContextProperty("RootWidth",screen.width());
    context->setContextProperty("RootHeight",screen.height());
    context->setContextProperty("backend",&bkend);
    context->setContextProperty("AFIM",bkend.AFIM);
    mainView->setSource(QUrl("qrc:MainUI.qml"));
    mainView->showFullScreen();
    return a.exec();
}
