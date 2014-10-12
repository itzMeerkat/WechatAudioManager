#include<backend.h>
#include <QApplication>

#include<QQuickView>
#include<QQmlContext>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Backend bkend;
    QQuickView *mainView=new QQuickView();
    QQmlContext *context=mainView->rootContext();
    context->setContextProperty("RootWidth",1024);
    context->setContextProperty("RootHeight",768);
    context->setContextProperty("backend",&bkend);
    context->setContextProperty("AFIM",bkend.AFIM);
    mainView->setSource(QUrl("qrc:MainUI.qml"));
    mainView->show();
    return a.exec();
}
