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
            Text {
                id:fd
                x:0
                text: duringTime
            }
            Text{
                x:fd.width+50
                text:createdTime
            }
            color: "yellow"
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
        color:"pink"
        MouseArea{
            anchors.fill: parent
            onClicked: {
                backend.searchAudioFile()
            }
        }
    }
    Rectangle{
        id:copyButton
        width:parent.width/3
        height:parent.height/8
        y:parent.height/8*7
        x:parent.width/3
        color: "yellow"
    }
    Rectangle{
        id:shareButton
        width:parent.width/3
        height:parent.height/8
        y:parent.height/8*7
        x:parent.width/3*2
        color: "black"
    }
}
