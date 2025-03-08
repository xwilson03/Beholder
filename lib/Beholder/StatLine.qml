import QtQuick
import QtQuick.Layouts

Rectangle {
    id: root
    property alias background: root.color
    property color text

    RowLayout {
        anchors.centerIn: parent

        Item { RowLayout.fillWidth: true }

        StatBox {
            stat: "STR"
            text: root.text
        }
        StatBox {
            stat: "DEX"
            text: root.text
        }
        StatBox {
            stat: "CON"
            text: root.text
        }
        StatBox {
            stat: "INT"
            text: root.text
        }
        StatBox {
            stat: "WIS"
            text: root.text
        }
        StatBox {
            stat: "CHA"
            text: root.text
        }

        Item { RowLayout.fillWidth: true }
    }
}