pragma Singleton

import QtQuick

Item {

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