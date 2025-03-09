import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import Beholder 1.0

Window {
    minimumWidth: 800
    minimumHeight: 600
    visible: true

    SplitView {
        anchors.fill: parent
        handle: Rectangle {
            implicitWidth: Theme.fg.thick
            implicitHeight: Theme.fg.thick
            color: Qt.lighter(Theme.fg.primary, SplitHandle.pressed ? 1.4 : SplitHandle.hovered ? 1.2 : 1.0)
        }

        Rectangle {
            SplitView.minimumWidth: 340
            color: Theme.fg.secondary

            MouseArea {
                anchors.fill: parent
                onClicked: forceActiveFocus()
            }

            ColumnLayout {
                anchors.fill: parent
                spacing: Theme.fg.thin

                NamePlate { ColumnLayout.fillWidth: true }

                StatLine {
                    ColumnLayout.fillWidth: true
                    ColumnLayout.minimumHeight: childrenRect.height + 25
                }

                CombatPanel {}

                Rectangle { // Filler
                    ColumnLayout.fillWidth: true
                    ColumnLayout.fillHeight: true
                    color: Theme.bg.secondary
                } // Filler
            }
        }

        Rectangle {
            SplitView.minimumWidth: 100
            SplitView.preferredWidth: 200
            SplitView.fillWidth: true
            color: Theme.bg.primary

            MouseArea {
                anchors.fill: parent
                onClicked: forceActiveFocus()
            }
        }

        Rectangle {
            SplitView.minimumWidth: 100
            color: Theme.bg.secondary

            MouseArea {
                anchors.fill: parent
                onClicked: forceActiveFocus()
            }

            ColumnLayout {
                anchors.fill: parent
                spacing: Theme.fg.thin

                EquipmentPanel {
                    ColumnLayout.fillWidth: true
                    ColumnLayout.minimumHeight: childrenRect.height + 10
                }

                Rectangle { // Filler
                    ColumnLayout.fillWidth: true
                    ColumnLayout.fillHeight: true
                    color: Theme.bg.secondary
                } // Filler
            }
        }
    }
}
