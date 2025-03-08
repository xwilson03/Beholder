import QtQuick
import QtQuick.Layouts

ColumnLayout {
    id: root
    property string stat
    property color text
    property color foreground

    Text {
        ColumnLayout.alignment: Qt.AlignHCenter
        text: parent.stat
        color: root.text
    }

    NumberInput{
        background: root.foreground
        text: root.text
    }

    Text {
        ColumnLayout.alignment: Qt.AlignHCenter
        text: "+1"
        color: root.text
    }
}