import QtQuick
import QtQuick.Layouts

ColumnLayout {
    id: root
    property string stat

    Text {
        ColumnLayout.alignment: Qt.AlignHCenter
        text: parent.stat
        color: Theme.text.primary
    }

    NumberInput {}

    Text {
        ColumnLayout.alignment: Qt.AlignHCenter
        text: "+1"
        color: Theme.text.primary
    }
}