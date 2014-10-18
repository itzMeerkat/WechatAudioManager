import QtQuick 2.0

Rectangle {
    width:RootWidth
    height:RootHeight
    id:root

    ListView{
        id:listview
        property int px
        property int py
        width:parent.width
        height:parent.height/4*3
        y:parent.height/8
        x:0
        model:AFIM
        delegate: Rectangle{
            width:listview.width
            height:RootHeight/10
            color:!(rank%2)?"#028098":"#8187C1"

            Text {
                id:fd
                x:0
                text: duringTime
                font.family: "微软雅黑"
                font.bold: true
                verticalAlignment: Text.AlignVCenter
                font.pointSize: 15
                styleColor: "#ffffff"
                color: "white"

            }
            Text{
                x:fd.width+50
                text:createdTime
                color: "white"
                font.family: "微软雅黑"
                font.bold: true
                verticalAlignment: Text.AlignVCenter
                font.pointSize: 15
                styleColor: "#ffffff"
            }

            Rectangle{
                z:10
                width:parent.height/4*3
                height:parent.height/4*3
                y:parent.height/8
                x:parent.width-parent.height
                Image{
                    anchors.fill: parent
                    source: "qrc:/icon/ticon.png"
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

    /*MouseArea{
        id:ma
        width:parent.width
        height:parent.height/4*3
        y:parent.height/8
        onPressed: {
            listview.px=ma.mouseX
            listview.py=ma.mouseY
        }
        onReleased: {
            console.log(listview.px-ma.mouseX)
            if(listview.px-ma.mouseX>RootWidth/5){
                backend.slide(0)
            }
            if(ma.mouseX-listview.px>RootWidth/5){
                backend.slide(1)
            }
        }
    }*/



    Rectangle{
        id:searchButton
        width:parent.width/3
        height:parent.height/8
        y:parent.height/8*7
        color:"#007DC7"
        MouseArea{
            anchors.fill: parent
            onClicked: {
                backend.searchAudioFile()
            }
            onPressed: {
                parent.color="#B0BADD"
            }
            onReleased: {
                parent.color="#007DC7"
            }
        }
        Text{
            anchors.centerIn: parent
            text:"搜索语音消息"
            color: "white"
            font.family: "微软雅黑"
            font.bold: true
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 15
            styleColor: "#ffffff"
        }
    }
    Rectangle{
        id:copyButton
        width:parent.width/3
        height:parent.height/8
        y:parent.height/8*7
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
    }

    Rectangle{
        id:shareButton
        width:parent.width/3
        height:parent.height/8
        y:parent.height/8*7
        x:parent.width/3*2
        color: "#007DC7"
        Text{
            anchors.centerIn: parent
            text:"设置"
            color: "white"
            font.family: "微软雅黑"
            //font.bold: true
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
            onClicked: {
                settingsView.visible=!settingsView.visible
            }
        }
    }

    //Header banner
    Rectangle{
        width:parent.width
        height:parent.height/8
        color:"lightblue"
        Text{
            height: parent.height
            width:parent.width/2
            text:"持续时间"
            font.family: "微软雅黑"
            font.bold: true
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter

            font.pointSize: 19
            color: "purple"
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
            color: "purple"
        }
    }

    Loader{
        id:settingsView
        source: "qrc:/Settings.qml"
        visible: false
    }
}
