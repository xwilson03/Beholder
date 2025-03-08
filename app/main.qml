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

    component StatBox: ColumnLayout {
        property string stat

        Text {
            ColumnLayout.alignment: Qt.AlignHCenter
            text: parent.stat
            color: theme.text.primary
        }

        NumberInput{
            background: theme.fg.secondary
            text: theme.text.primary
        }

        Text {
            ColumnLayout.alignment: Qt.AlignHCenter
            text: "+1"
            color: theme.text.primary
        }
    } // StatBox

    component StatLine: Rectangle {
        ColumnLayout.fillWidth: true
        ColumnLayout.minimumHeight: childrenRect.height + 25
        color: theme.bg.secondary

        RowLayout {
            anchors.centerIn: parent

            Item { RowLayout.fillWidth: true }

            StatBox {stat: "STR"} // Strength
            StatBox {stat: "DEX"} // Dexterity
            StatBox {stat: "CON"} // Constitution
            StatBox {stat: "INT"} // Intelligence
            StatBox {stat: "WIS"} // Wisdom
            StatBox {stat: "CHA"} // Charisma

            Item { RowLayout.fillWidth: true }
        }
    } // StatLine

    component CombatPanel: Rectangle {
        ColumnLayout.fillWidth: true
        ColumnLayout.minimumHeight: childrenRect.height + 25
        color: theme.bg.secondary

        ColumnLayout {
            anchors.centerIn: parent
            RowLayout {
                spacing: 20
                Item { RowLayout.fillWidth: true }

                ColumnLayout {
                    Text {
                        ColumnLayout.alignment: Qt.AlignHCenter
                        color: theme.text.primary
                        text: "HP"
                    }
                    NumberInput {
                        ColumnLayout.alignment: Qt.AlignHCenter
                        width: 100
                        height: 50
                        background: theme.fg.secondary
                        text: theme.text.primary
                    }
                }

                ColumnLayout {
                    Text {
                        ColumnLayout.alignment: Qt.AlignHCenter
                        color: theme.text.primary
                        text: "Temporary HP"
                    }
                    NumberInput {
                        ColumnLayout.alignment: Qt.AlignHCenter
                        width: 100
                        height: 50
                        background: theme.fg.secondary
                        text: theme.text.primary
                    }
                }
                Item { RowLayout.fillWidth: true }
            }

            RowLayout {
                spacing: 20

                Item { RowLayout.fillWidth: true }

                ColumnLayout {
                    Text {
                        ColumnLayout.alignment: Qt.AlignHCenter
                        color: theme.text.primary
                        text: "Max HP"
                    }
                    NumberInput {
                        ColumnLayout.alignment: Qt.AlignHCenter
                        background: theme.fg.secondary
                        text: theme.text.primary
                    }
                }

                ColumnLayout {
                    Text {
                        ColumnLayout.alignment: Qt.AlignHCenter
                        color: theme.text.primary
                        text: "Armor"
                    }
                    NumberInput {
                        ColumnLayout.alignment: Qt.AlignHCenter
                        background: theme.fg.secondary
                        text: theme.text.primary
                    }
                }

                ColumnLayout {
                    Text {
                        ColumnLayout.alignment: Qt.AlignHCenter
                        color: theme.text.primary
                        text: "Initiative"
                    }
                    NumberInput {
                        ColumnLayout.alignment: Qt.AlignHCenter
                        background: theme.fg.secondary
                        text: theme.text.primary
                    }
                }

                ColumnLayout {
                    Text {
                        ColumnLayout.alignment: Qt.AlignHCenter
                        color: theme.text.primary
                        text: "Speed"
                    }
                    NumberInput {
                        ColumnLayout.alignment: Qt.AlignHCenter
                        background: theme.fg.secondary
                        text: theme.text.primary
                    }
                }

                Item { RowLayout.fillWidth: true }
            }
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
