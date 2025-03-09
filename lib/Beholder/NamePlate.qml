import QtQuick

Rectangle {
    id: root
    height: 40
    color: Theme.bg.secondary

    Text {
        id: content
        anchors.centerIn: parent
        text: "John Doe, Human Bard 1"
        font.pointSize: 14
        color: Theme.text.primary
    }
}