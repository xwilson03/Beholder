import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import Beholder 1.0

Window {
    minimumWidth: 800
    minimumHeight: 600
    visible: true

    Theme {
        id: theme
    }

    SplitView {
        anchors.fill: parent
        handle: Rectangle {
            implicitWidth: theme.fg.thick
            implicitHeight: theme.fg.thick
            color: Qt.lighter(theme.fg.primary, SplitHandle.pressed ? 1.4 : SplitHandle.hovered ? 1.2 : 1.0)
        }

        Rectangle {
            SplitView.minimumWidth: 340
            color: theme.fg.secondary

            MouseArea {
                anchors.fill: parent
                onClicked: forceActiveFocus()
            }

            ColumnLayout {
                anchors.fill: parent
                spacing: theme.fg.thin

                NamePlate {
                    ColumnLayout.fillWidth: true
                    primary: theme.bg.secondary
                    text: theme.text.primary
                }

                StatLine {
                    ColumnLayout.fillWidth: true
                    ColumnLayout.minimumHeight: childrenRect.height + 25
                    background: theme.bg.secondary
                    foreground: theme.fg.secondary
                    text: theme.text.primary
                }

                CombatPanel {
                    background: theme.bg.secondary
                    foreground: theme.fg.secondary
                    text: theme.text.primary
                }

                Rectangle { // Filler
                    ColumnLayout.fillWidth: true
                    ColumnLayout.fillHeight: true
                    color: theme.bg.secondary
                } // Filler
            }
        }

        Rectangle {
            SplitView.minimumWidth: 100
            SplitView.preferredWidth: 200
            SplitView.fillWidth: true
            color: theme.bg.primary

            MouseArea {
                anchors.fill: parent
                onClicked: forceActiveFocus()
            }
        }

        Rectangle {
            SplitView.minimumWidth: 100
            color: theme.bg.secondary

            MouseArea {
                anchors.fill: parent
                onClicked: forceActiveFocus()
            }

            ColumnLayout {
                anchors.fill: parent
                spacing: theme.fg.thin

                EquipmentPanel {
                    ColumnLayout.fillWidth: true
                    ColumnLayout.minimumHeight: childrenRect.height + 10
                    color: theme.bg.secondary
                }

                Rectangle { // Filler
                    ColumnLayout.fillWidth: true
                    ColumnLayout.fillHeight: true
                    color: theme.bg.secondary
                } // Filler
            }
        }
    }
}
