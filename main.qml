import QtQuick 2.0
import Material 1.0

Rectangle {
    width: 320
    height: 480
    color: "black"

    Column {
        anchors.fill: parent

        MaterialItem {
            width: parent.width;
            height: parent.height;
            color: "#007fc0"//
        }

        /*MaterialItem {
            width: parent.width;
            height: parent.height / 3;
            color: "White"
        }

        MaterialItem {
            width: parent.width;
            height: parent.height / 3;
            color: "springgreen"
        }*/
    }
}
