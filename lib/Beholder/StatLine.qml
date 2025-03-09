import QtQuick
import QtQuick.Layouts

Rectangle {
    id: root
    color: Theme.bg.secondary

    RowLayout {
        anchors.centerIn: parent

        Item { RowLayout.fillWidth: true }

        StatBox { stat: "STR" }
        StatBox { stat: "DEX" }
        StatBox { stat: "CON" }
        StatBox { stat: "INT" }
        StatBox { stat: "WIS" }
        StatBox { stat: "CHA" }

        Item { RowLayout.fillWidth: true }
    }
}