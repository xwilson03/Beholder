import QtQuick

Rectangle {
    id: root
    height: 40

    property alias primary: root.color
    property alias text: content.color

    Text {
        id: content
        anchors.centerIn: parent
        text: "John Doe, Human Bard 1"
        font.pointSize: 14
    }
}