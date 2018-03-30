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
            height: parent.height / 3;
            color: "steelblue"
        }

        MaterialItem {
            width: parent.width;
            height: parent.height / 3;
            color: "darkorchid"
        }

        MaterialItem {
            width: parent.width;
            height: parent.height / 3;
            color: "springgreen"
        }
    }
}
