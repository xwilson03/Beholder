import QtQuick
import QtQuick.Layouts

Rectangle {
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