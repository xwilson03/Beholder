import QtQuick
import QtQuick.Layouts

Rectangle {
    id: root
    ColumnLayout.fillWidth: true
    ColumnLayout.minimumHeight: childrenRect.height + 25

    property alias background: root.color
    property color foreground
    property color text

    ColumnLayout {
        anchors.centerIn: parent
        RowLayout {
            spacing: 20
            Item { RowLayout.fillWidth: true }

            ColumnLayout {
                Text {
                    ColumnLayout.alignment: Qt.AlignHCenter
                    color: root.text
                    text: "HP"
                }
                NumberInput {
                    ColumnLayout.alignment: Qt.AlignHCenter
                    width: 100
                    height: 50
                    background: root.foreground
                    text: root.text
                }
            }

            ColumnLayout {
                Text {
                    ColumnLayout.alignment: Qt.AlignHCenter
                    color: root.text
                    text: "Temporary HP"
                }
                NumberInput {
                    ColumnLayout.alignment: Qt.AlignHCenter
                    width: 100
                    height: 50
                    background: root.foreground
                    text: root.text
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
                    color: root.text
                    text: "Max HP"
                }
                NumberInput {
                    ColumnLayout.alignment: Qt.AlignHCenter
                    background: root.foreground
                    text: root.text
                }
            }

            ColumnLayout {
                Text {
                    ColumnLayout.alignment: Qt.AlignHCenter
                    color: root.text
                    text: "Armor"
                }
                NumberInput {
                    ColumnLayout.alignment: Qt.AlignHCenter
                    background: root.foreground
                    text: root.text
                }
            }

            ColumnLayout {
                Text {
                    ColumnLayout.alignment: Qt.AlignHCenter
                    color: root.text
                    text: "Initiative"
                }
                NumberInput {
                    ColumnLayout.alignment: Qt.AlignHCenter
                    background: root.foreground
                    text: root.text
                }
            }

            ColumnLayout {
                Text {
                    ColumnLayout.alignment: Qt.AlignHCenter
                    color: root.text
                    text: "Speed"
                }
                NumberInput {
                    ColumnLayout.alignment: Qt.AlignHCenter
                    background: root.foreground
                    text: root.text
                }
            }

            Item { RowLayout.fillWidth: true }
        }
    }
}