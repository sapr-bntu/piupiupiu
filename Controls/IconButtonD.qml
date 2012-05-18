// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Rectangle {
     id:downbutt
    signal clicked

    width: 28
    height: 100
    gradient: Gradient {
    GradientStop  {position: 1; color: "grey"}
    GradientStop { position: 0; color: "darkgrey"}
                        }

    Image {
        id: img
        source: "../pics/down.PNG"
        anchors.fill: parent

           }

    MouseArea   {
        anchors.fill: parent
        hoverEnabled: true

        onClicked: { downbutt.clicked()

        console.log("piuDOWN")
    }


                }

}
