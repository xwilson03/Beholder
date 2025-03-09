import QtQuick
import QtQuick.Layouts

Rectangle {
    id: root
    ColumnLayout.fillWidth: true
    ColumnLayout.minimumHeight: childrenRect.height + 25

    color: Theme.bg.secondary

    ColumnLayout {
        anchors.centerIn: parent

        RowLayout {
            spacing: 20

            Item { RowLayout.fillWidth: true }

            ColumnLayout {
                Text {
                    ColumnLayout.alignment: Qt.AlignHCenter
                    color: Theme.text.primary
                    text: "HP"
                }
                NumberInput {
                    ColumnLayout.alignment: Qt.AlignHCenter
                    width: 100
                    height: 50
                }
            }

            ColumnLayout {
                Text {
                    ColumnLayout.alignment: Qt.AlignHCenter
                    color: Theme.text.primary
                    text: "Temporary HP"
                }
                NumberInput {
                    ColumnLayout.alignment: Qt.AlignHCenter
                    width: 100
                    height: 50
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
                    color: Theme.text.primary
                    text: "Max HP"
                }
                NumberInput { ColumnLayout.alignment: Qt.AlignHCenter }
            }

            ColumnLayout {
                Text {
                    ColumnLayout.alignment: Qt.AlignHCenter
                    color: Theme.text.primary
                    text: "Armor"
                }
                NumberInput { ColumnLayout.alignment: Qt.AlignHCenter }
            }

            ColumnLayout {
                Text {
                    ColumnLayout.alignment: Qt.AlignHCenter
                    color: Theme.text.primary
                    text: "Initiative"
                }
                NumberInput { ColumnLayout.alignment: Qt.AlignHCenter }
            }

            ColumnLayout {
                Text {
                    ColumnLayout.alignment: Qt.AlignHCenter
                    color: Theme.text.primary
                    text: "Speed"
                }
                NumberInput { ColumnLayout.alignment: Qt.AlignHCenter }
            }

            Item { RowLayout.fillWidth: true }
        }
    }
}