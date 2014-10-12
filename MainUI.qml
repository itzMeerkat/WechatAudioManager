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
        delegate: Text { text: duringTime + ", " + createdTime }
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
