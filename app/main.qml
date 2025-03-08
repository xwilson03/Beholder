import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import Beholder 1.0

Window {
    minimumWidth: 800
    minimumHeight: 600
    visible: true

    property Item theme: Item {

        property Item bg: Item {
            property color primary: "#191918"
            property color secondary: "#2c2c2a"
            property color accent: "#303030"
        }

        property Item fg: Item {
            property color primary: "#606060"
            property color secondary: "#444444"
            property int thick: 4
            property int thin: 2
        }

        property Item text: Item {
            property color primary: "#ffffff"
        }
    }

    component EquipmentPanel: Rectangle {
        ColumnLayout.fillWidth: true
        ColumnLayout.minimumHeight: childrenRect.height + 10
        color: theme.bg.secondary
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
                }
                CombatPanel {}

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

                EquipmentPanel {}

                Rectangle { // Filler
                    ColumnLayout.fillWidth: true
                    ColumnLayout.fillHeight: true
                    color: theme.bg.secondary
                } // Filler
            }
        }
    }
}
