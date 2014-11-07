import QtQuick 2.0
import "qrc:/qmls/"

Rectangle{
    width: RootWidth/2
    height:RootHeight/8
    color: "transparent"

    Text{
        anchors.centerIn: parent
        text:"文件已复制到/sdcard/WeChatAudioManager中~\n戳我关闭"
        font.family: "微软雅黑"
        horizontalAlignment: Text.AlignHCenter
        font.pointSize: 12
    }
}
