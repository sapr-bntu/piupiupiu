import QtQuick 1.0
//p

Rectangle {
    property alias text: textElement.text
    property string rsGradientStop0: "Black"
    property string rsGradientStop1: "darkgrey"
    property string rsGradientStop2: "red"

    signal clicked
    id: greyButton
    width: 100
    height: 30
    border.color: "Black"
    gradient: Gradient {
        GradientStop {
            id: gradientStop0
            position: 0
            color: rsGradientStop0
        }
        GradientStop {
            id: gradientStop1
            position: 1
            color: rsGradientStop1
        }
        GradientStop {
            id: gradientStop2
            position: 2
            color: rsGradientStop2
        }
    }
    Text {
        id: textElement
        color: "yellow"
        font.underline: false
        font.bold: false
        font.pixelSize: 12
        anchors.centerIn: parent
    }
    ParallelAnimation {
        id: mouseEnterAnim
        PropertyAnimation {
            target: gradientStop0
            properties: "color"
            to: rsGradientStop1
            duration: 300
        }
        PropertyAnimation {
            target: gradientStop1
            properties: "color"
            to: rsGradientStop0
            duration: 300
        }
    }
    ParallelAnimation {
        id: mouseExitAnim
        PropertyAnimation {
            target: gradientStop0
            properties: "color"
            to: rsGradientStop0
            duration: 300
        }
        PropertyAnimation {
            target: gradientStop1
            properties: "color"
            to: rsGradientStop1
            duration: 300
        }
    }

    ParallelAnimation {
        id: mouseClickAnim
        PropertyAnimation {
            target: gradientStop2
            properties: "color"
            to: rsGradientStop1
            duration: 50
        }
        PropertyAnimation {
            target: gradientStop1
            properties: "color"
            to: rsGradientStop2
            duration: 50
        }
    }
        ParallelAnimation {
            id: mouseNoClickAnim
            PropertyAnimation {
                target: gradientStop0
                properties: "color"
                to: rsGradientStop0
                duration: 50
            }
            PropertyAnimation {
                target: gradientStop1
                properties: "color"
                to: rsGradientStop1
                duration: 50
            }
        }
    MouseArea {
        id: mouse
        anchors.fill: greyButton
        hoverEnabled: true
        onEntered: mouseEnterAnim.start()
        onExited: mouseExitAnim.start()
        onPressed: mouseClickAnim.start()
        onReleased: mouseNoClickAnim.start()
        onClicked: greyButton.clicked()
    }
}
