import QtQuick
import QtQuick.Controls

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

    SplitView {
        anchors.fill: parent
        handle: Rectangle {
            implicitWidth: theme.fg.thick
            implicitHeight: theme.fg.thick
            color: Qt.lighter(theme.fg.primary, SplitHandle.pressed ? 1.4 : SplitHandle.hovered ? 1.2 : 1.0)
        }

        Rectangle {
            SplitView.preferredWidth: 200
            SplitView.minimumWidth: 340
            color: theme.fg.secondary
        }
        Rectangle {
            SplitView.minimumWidth: 100
            SplitView.preferredWidth: 200
            SplitView.fillWidth: true
            color: theme.bg.primary
        }
        Rectangle {
            SplitView.minimumWidth: 100
            SplitView.preferredWidth: 200
            color: theme.bg.secondary
        }
    }
}
