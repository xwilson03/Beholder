import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Window {
    minimumWidth: 800
    minimumHeight: 600
    visible: true

    property Item theme: Item {

        property Item bg: Item {
            property color primary: "#202020"
            property color secondary: "#2a2a2a"
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

    component NamePlate: Rectangle {
        ColumnLayout.fillWidth: true
        height: 40
        color: theme.bg.secondary

        Text {
            anchors.centerIn: parent
            text: "John Doe, Human Bard 1"
            font.pointSize: 14
            color: theme.text.primary
        }
    } // NamePlate

    component StatBox: ColumnLayout {
        property string stat

        Text {
            ColumnLayout.alignment: Qt.AlignHCenter
            text: parent.stat
            color: theme.text.primary
        }

        Rectangle {
            width: 50
            height: 50
            color: theme.fg.secondary
            radius: 10

            MouseArea {
                anchors.fill: parent
                cursorShape: Qt.IBeamCursor
            }

            TextInput {
                anchors.fill: parent
                padding: parent.radius
                color: theme.text.primary
                font.pointSize: 20

                horizontalAlignment: TextInput.AlignHCenter
                verticalAlignment: TextInput.AlignVCenter
                validator: IntValidator { bottom: 0; top: 30 }

                text: "0"
            }
        }

        Text {
            ColumnLayout.alignment: Qt.AlignHCenter
            text: "+1"
            color: theme.text.primary
        }
    } // StatBox

    component StatLine: Rectangle {
        ColumnLayout.fillWidth: true
        ColumnLayout.minimumHeight: childrenRect.height + 10
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

                NamePlate {}
                StatLine {}

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
            SplitView.preferredWidth: 200
            color: theme.bg.secondary

            MouseArea {
                anchors.fill: parent
                onClicked: forceActiveFocus()
            }
        }
    }
}
