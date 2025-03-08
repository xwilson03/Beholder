import QtQuick
import QtQuick.Layouts

Rectangle {
    color: theme.bg.secondary

    RowLayout {
        anchors.centerIn: parent

        Item { RowLayout.fillWidth: true }

        StatBox {
            stat: "STR"
            text: theme.text.primary
        }
        StatBox {
            stat: "DEX"
            text: theme.text.primary
        }
        StatBox {
            stat: "CON"
            text: theme.text.primary
        }
        StatBox {
            stat: "INT"
            text: theme.text.primary
        }
        StatBox {
            stat: "WIS"
            text: theme.text.primary
        }
        StatBox {
            stat: "CHA"
            text: theme.text.primary
        }

        Item { RowLayout.fillWidth: true }
    }
}