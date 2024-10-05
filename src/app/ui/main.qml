import QtQuick
import QtQuick.Controls

Window {
    minimumWidth: 800
    minimumHeight: 600
    visible: true

    property Item style: Item {
        property Item main: Item {
            property color bg: "#222222"
        }

        property Item pane: Item {
            property color bg: "#2a2a2a"
        }

        property Item handle: Item {
            property color bg: "#606060"
        }
    }

    SplitView {
        anchors.fill: parent
        handle: Rectangle {
            implicitWidth: 4
            implicitHeight: 4
            color: Qt.lighter(style.handle.bg, SplitHandle.pressed ? 1.4 : SplitHandle.hovered ? 1.2 : 1.0)
        }

        Rectangle {
            SplitView.minimumWidth: 100
            SplitView.preferredWidth: 200
            color: style.pane.bg
        }
        Rectangle {
            SplitView.minimumWidth: 100
            SplitView.preferredWidth: 200
            SplitView.fillWidth: true
            color: style.main.bg
        }
        Rectangle {
            SplitView.minimumWidth: 100
            SplitView.preferredWidth: 200
            color: style.pane.bg
        }
    }
}
