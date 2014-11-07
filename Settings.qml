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
import QtQuick 2.0

Rectangle {
    x:RootWidth/6
    y:RootHeight/6
    width: RootWidth/3*2
    height: RootHeight/3*2
    color:"transparent"
    /*Image{
        anchors.fill: parent
        source: "qrc:/img/bg.jpg"
    }*/
    Rectangle{
        anchors.fill: parent
        color: "white"
        opacity: 0.9
    }

    Text{
        anchors.centerIn: parent
        width:parent.width/5*4
        height:parent.height
        text:"本软件遵从GPLv3协议，鼓励开发者在遵从协议的基础上进行二次开发。\n This software is following GPLv3 license, encouraging devlopers to keep developing while complying the GPLv3 license.\n\n联系方式Contact：\nE-Mail:bf109g2@126.com\n手机Phone:18612363582"
        font.family: "微软雅黑"
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        wrapMode: Text.Wrap
        font.pointSize: 13
    }
}
