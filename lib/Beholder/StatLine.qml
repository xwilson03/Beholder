import QtQuick
import QtQuick.Layouts

Rectangle {
    id: root
    property alias background: root.color
    property color text
    property color foreground

    RowLayout {
        anchors.centerIn: parent

        Item { RowLayout.fillWidth: true }

        StatBox {
            stat: "STR"
            text: root.text
            foreground: root.foreground
        }
        StatBox {
            stat: "DEX"
            text: root.text
            foreground: root.foreground
        }
        StatBox {
            stat: "CON"
            text: root.text
            foreground: root.foreground
        }
        StatBox {
            stat: "INT"
            text: root.text
            foreground: root.foreground
        }
        StatBox {
            stat: "WIS"
            text: root.text
            foreground: root.foreground
        }
        StatBox {
            stat: "CHA"
            text: root.text
            foreground: root.foreground
        }

        Item { RowLayout.fillWidth: true }
    }
}