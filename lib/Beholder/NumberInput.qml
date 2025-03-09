import QtQuick

Rectangle {
    id: root
    width: 50
    height: 50
    radius: 10

    color: Theme.fg.secondary

    MouseArea {
        anchors.fill: parent
        cursorShape: Qt.IBeamCursor
    }

    TextInput {
        id: input
        anchors.fill: parent
        padding: parent.radius
        font.pointSize: 20

        horizontalAlignment: TextInput.AlignHCenter
        verticalAlignment: TextInput.AlignVCenter
        validator: IntValidator { bottom: 0; top: 30 }

        text: "0"
        color: Theme.text.primary
    }
}