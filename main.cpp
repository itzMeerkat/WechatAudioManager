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
    mainView->setSource(QUrl("qrc:/qmls/MainUI.qml"));
    mainView->showFullScreen();
    return a.exec();
}
