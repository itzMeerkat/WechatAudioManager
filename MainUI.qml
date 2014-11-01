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
import QtQuick 2.2
import QtQuick.Controls 1.2
//import QtWebKit 3.0

Rectangle {
    width:RootWidth
    height:RootHeight
    id:root

    Image{
        source: "./img/bg.jpg"
        anchors.fill: parent
    }

    ListView{
        id:listview
        property int px
        property int py
        width:parent.width
        height:parent.height/36*23
        y:parent.height/9
        x:0
        model:AFIM
        delegate: Rectangle{
            width:listview.width
            height:RootHeight/10
            color:"Transparent"
            //border.color: "black"
            Rectangle{
                opacity:rank%2?0.5:0.3;
                anchors.fill: parent
            }

            Text {
                id:fd
                x:0
                text: duringTime
                font.family: "微软雅黑"
                font.bold: true
                verticalAlignment: Text.AlignVCenter
                font.pointSize: 15
                //styleColor: "#ffffff"
                //color: "white"

            }
            Text{
                x:fd.width+50
                text:createdTime
                //color: "white"
                font.family: "微软雅黑"
                font.bold: true
                verticalAlignment: Text.AlignVCenter
                font.pointSize: 15
                //styleColor: "#ffffff"
            }

            Rectangle{
                z:10
                width:parent.height/4*3
                height:parent.height/4*3
                y:parent.height/8
                x:parent.width-parent.height
                color:"transparent"
                Image{
                    anchors.fill: parent
                    source: "qrc:/icon/copy.png"

                }

                MouseArea{
                    z:10
                    anchors.fill: parent
                    onClicked: {
                        backend.copyFile(rank)
                    }
                }
            }


            MouseArea{
                anchors.fill: parent
                onClicked: {
                    backend.playSound(rank)
                }
            }
        }
    }

    Rectangle{
        id:searchButton
        width:parent.width/2
        height:parent.height/8
        y:parent.height/4*3
        color:"Transparent"
        Rectangle{
            id:sbwbg
            opacity: 0.8
            anchors.fill: parent
        }
        MouseArea{
            anchors.fill: parent
            onClicked: {
                backend.searchAudioFile()
            }
            onPressed: {
                sbwbg.opacity=0.5
            }
            onReleased: {
                sbwbg.opacity=0.8
            }
        }
        Text{
            anchors.centerIn: parent
            text:"搜索语音消息"
            //color: "white"
            font.family: "微软雅黑"
            font.bold: true
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 15
            //styleColor: "#ffffff"
        }
    }
    /*Rectangle{
        id:copyButton
        width:parent.width/3
        height:parent.height/8
        y:parent.height/4*3
        x:parent.width/3
        color: "#007DC7"
        Text{
            anchors.centerIn: parent
            text:"待定"
            color: "white"
            font.family: "微软雅黑"
            font.bold: true
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 15
            styleColor: "#ffffff"
        }
        MouseArea{
            anchors.fill: parent
            onPressed: {
                parent.color="#B0BADD"
            }
            onReleased: {
                parent.color="#007DC7"
            }
        }
    }*/

    Rectangle{
        id:settingButton
        width:parent.width/2
        height:parent.height/8
        y:parent.height/4*3
        x:parent.width/2
        color:"Transparent"
        Rectangle{
            id:setwbg
            opacity: 0.8
            anchors.fill: parent
        }
        Text{
            anchors.centerIn: parent
            text:"设置"
            //color: "white"
            font.family: "微软雅黑"
            font.bold: true
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 15
            //styleColor: "#ffffff"
        }
        MouseArea{
            anchors.fill: parent
            onPressed: {
                setwbg.opacity=0.5
            }
            onReleased: {
                setwbg.opacity=0.8
            }
            onClicked: {
                settingsView.visible=!settingsView.visible
            }
        }
    }

    //Header banner
    Rectangle{
        Rectangle{
            opacity: 0.8
            anchors.fill: parent
        }
        width:parent.width
        height:parent.height/9
        color:"Transparent"

        Text{
            height: parent.height
            width:parent.width/2
            text:"持续时间"
            font.family: "微软雅黑"
            font.bold: true
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter

            font.pointSize: 19
            //color: "purple"
        }
        Text{
            height: parent.height
            width:parent.width/2
            x:parent.width/2
            text:"创建时间"
            font.family: "微软雅黑"
            font.bold: true
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pointSize: 19
            //color: "purple"
        }
    }

    Loader{
        id:settingsView
        source: "qrc:/Settings.qml"
        visible: false
    }

    /*WebView {
        id: webview
        width: parent.width
        height:RootHeight/8
        y:RootHeight/8*7
        url: "file:/GitHub-pro/WechatAudioManager/banner.html"
        //anchors.fill: parent
        onNavigationRequested: {
        // detect URL scheme prefix, most likely an external link
            var schemaRE = /^\w+:/;
            if (schemaRE.test(request.url)) {
                request.action = WebView.AcceptRequest;
            } else {
                request.action = WebView.IgnoreRequest;
                // delegate request.url here
            }
        }
    }*/
    Rectangle {
        width: parent.width
        height:RootHeight/8
        y:RootHeight/8*7
        color: "black"
        Text{
            anchors.centerIn: parent
            text:"广告位"
            color: "white"
        }
    }
    /*MouseArea{
        z:50
        anchors.fill: parent
        onClicked: {
            advBanner.url="./a.html"
        }
    }*/
}
