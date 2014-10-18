import QtQuick 2.0

Rectangle {
    x:RootWidth/6
    y:RootHeight/6
    width: RootWidth/3*2
    height: RootHeight/3*2
    Text{
        anchors.centerIn: parent
        width:parent.width/5*4
        height:parent.height
        text:"现在还没有什么好设置的是吧。。\n本软件遵从GPLv3协议，鼓励开发者在遵从协议的基础上进行二次开发。\n This software is following GPLv3 license, encouraging devlopers to keep developing while complying the GPLv3 license.\n\n联系方式Contact：\nE-Mail:bf109g2@126.com\n手机Phone:18612363582"
        font.family: "微软雅黑"
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        wrapMode: Text.Wrap
        font.pointSize: 13
    }
    color:"red"
}
