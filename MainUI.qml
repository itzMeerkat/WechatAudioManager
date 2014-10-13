import QtQuick 2.0

Rectangle {
    width:RootWidth
    height:RootHeight
    id:root;
    ListView{
        id:listview
        width:parent.width
        height:parent.height/8*7

        x:0
        y:0
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
}
