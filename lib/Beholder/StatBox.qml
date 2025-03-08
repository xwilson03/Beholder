import QtQuick
import QtQuick.Layouts

ColumnLayout {
    id: root
    property string stat
    property color text

    Text {
        ColumnLayout.alignment: Qt.AlignHCenter
        text: parent.stat
        color: root.text
    }

    NumberInput{
        background: theme.fg.secondary
        text: root.text
    }

    Text {
        ColumnLayout.alignment: Qt.AlignHCenter
        text: "+1"
        color: root.text
    }
}