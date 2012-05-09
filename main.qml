import QtQuick 1.1
import Qt 4.7
import "Controls"



Rectangle {
    id: rectangle1
    width: 800
    height: 640
    color: "#FF4E4E4E"





    GreyButton {
        id: mgreybutton1
        x: 0
        y: 5
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenterOffset: -350
        anchors.verticalCenterOffset: -300
        text: "Unzip *.chm"
        onClicked: window.FunctionPIU()

    }

    GreyButton {
        id: mgreybutton2
        x: 208
        y: 169
        anchors.horizontalCenterOffset: -250
        anchors.verticalCenterOffset: -300
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        text: "Delete *.htm"
        onClicked:
        window.FunctionPIUPIUPIU()




    }


    GreyButton {
        id: mgreybutton3
        x: 210
        y: 0
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenterOffset: -150
        anchors.verticalCenterOffset: -300
        text: "Save As"
        onClicked:
         window.savik(textEdit.text);



    }



      GreyButton {
        id: mgreybutton4
        x: 300
        y: 5
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenterOffset: -50
        anchors.verticalCenterOffset: -300
        text: "Open *.htm"
        onClicked:

        {
            textEdit.text = window.FunctionMDE();
               }





    }



      GreyButton {
          id: mgreybutton5
         // x: 0
        //  y: 0
          anchors.horizontalCenter: parent.horizontalCenter
          anchors.verticalCenter: parent.verticalCenter
          anchors.horizontalCenterOffset: 50
          anchors.verticalCenterOffset: -300
          text: "Exit"
          onClicked:
          {

              window.close()
          }




         }


      Rectangle {
          id:textArea
          x: 7
          y: 51
          width :484; height:400
         // property color fontColor: "white"
          //property alias textContent: textEdit.text
          Flickable {
              id: flickArea
              x: 0
              y: 0
              width: parent.width; height: parent.height
              anchors.rightMargin: 0
              anchors.bottomMargin: 0
              anchors.leftMargin: 0
              anchors.topMargin: 0
              anchors.fill:parent
              boundsBehavior: Flickable.StopAtBounds
              flickableDirection: Flickable.HorizontalFlick
              interactive: true
              function ensureVisible(r) {
                  if (contentX >= r.x)
                  contentX = r.x;
                  else if (contentX+width <= r.x+r.width)
                  contentX = r.x+r.width-width;
                  if (contentY >= r.y)
                  contentY = r.y;
                  else if (contentY+height <= r.y+r.height)
                  contentY = r.y+r.height-height;
              }

              TextEdit {
                  id: textEdit
                  x: 0
                  y: 0
                  anchors.fill:parent
                  width:parent.width; height:parent.height
                  color:fontColor
                  anchors.rightMargin: 0
                  anchors.bottomMargin: 0
                  anchors.leftMargin: 0
                  anchors.topMargin: 0
                  focus: true
                  wrapMode: TextEdit.Wrap
                  font.pointSize:10
                  onCursorRectangleChanged: flickArea.ensureVisible(cursorRectangle)
                  selectByMouse: true
              }
          }
      }




// This example illustrates expanding a list item to show a more detailed view.
//glavnoe okno
Rectangle {
    id: page
    width: 285; height: 300
    color: "black"
    anchors.horizontalCenter: parent.horizontalCenter
    anchors.verticalCenter: parent.verticalCenter
    anchors.horizontalCenterOffset: 250
    anchors.verticalCenterOffset: -165

    // Delegate for the recipes.  This delegate has two modes:
    // 1. List mode (default), which just shows the picture and title of the recipe.
    // 2. Details mode, which also shows the ingredients and method.
    Component {
        id: recipeDelegate

        Item {
            id: recipe

            // Create a property to contain the visibility of the details.
            // We can bind multiple element's opacity to this one property,
            // rather than having a "PropertyChanges" line for each element we
            // want to fade.
            property real detailsOpacity : 0

            width: listView.width
            height: 60
            //70

            // A simple rounded rectangle for the background
            Rectangle {
                id: background
                x: 2; y: 2; width: parent.width - x*1; height: parent.height - y*1
                color: "grey"
                border.color: "black"
                radius: 5
            }

            // This mouse region covers the entire delegate.
            // When clicked it changes mode to 'Details'.  If we are already
            // in Details mode, then no change will happen.
            MouseArea {
                anchors.fill: parent
                onClicked: recipe.state = 'Details';
            }

            // Lay out the page: picture, title and ingredients at the top, and method at the
            // bottom.  Note that elements that should not be visible in the list
            // mode have their opacity set to recipe.detailsOpacity.
            Row {
                id: topLayout
                x: 10; y: 10; height: recipeImage.height; width: parent.width
                spacing: 10

                Image {
                    id: recipeImage
                    width: 40; height: 40
                    source: picture
                }

                Column {
                    width: background.width - recipeImage.width - 20; height: recipeImage.height
                    spacing: 5

                    Text {
                        text: title
                        font.bold: true; font.pointSize: 16
                    }

                    Text {
                        text: ""
                        font.pointSize: 12; font.bold: true
                        opacity: recipe.detailsOpacity
                    }

                    Text {
                        text: ingredients
                        wrapMode: Text.WordWrap
                        width: parent.width
                        opacity: recipe.detailsOpacity
                    }
                }
            }

            Item {
                id: details
                x: 10; width: parent.width - 20
                anchors { top: topLayout.bottom; topMargin: 10; bottom: parent.bottom; bottomMargin: 10 }
                opacity: recipe.detailsOpacity

                Text {
                    id: methodTitle
                    anchors.top: parent.top
                    text: "Real Name:"
                    font.pointSize: 12; font.bold: true
                }

                Flickable {
                    id: flick
                    width: parent.width
                    anchors { top: methodTitle.bottom; bottom: parent.bottom }
                    contentHeight: methodText.height
                    clip: true

                    Text { id: methodText; text: method; wrapMode: Text.WordWrap; width: details.width }
                }

                Image {
                    anchors { right: flick.right; top: flick.top }
                    source: "pics/moreUp.png"
                    opacity: flick.atYBeginning ? 0 : 1
                }

                Image {
                    anchors { right: flick.right; bottom: flick.bottom }
                    source: "pics/moreDown.png"
                    opacity: flick.atYEnd ? 0 : 1
                }
            }

            // A button to close the detailed view, i.e. set the state back to default ('').
            TextButton {
                y: 10
                anchors { right: background.right; rightMargin: 10 }
                opacity: recipe.detailsOpacity
                text: "close"

                onClicked: recipe.state = '';
            }

            states: State {
                name: "Details"

                PropertyChanges { target: background; color: "lightgrey" }
                PropertyChanges { target: recipeImage; width: 130; height: 130 } // Make picture bigger
                PropertyChanges { target: recipe; detailsOpacity: 1; x: 0 } // Make details visible
                PropertyChanges { target: recipe; height: listView.height } // Fill the entire list area with the detailed view

                // Move the list so that this item is at the top.
                PropertyChanges { target: recipe.ListView.view; explicit: true; contentY: recipe.y }

                // Disallow flicking while we're in detailed view
                PropertyChanges { target: recipe.ListView.view; interactive: false }
            }

            transitions: Transition {
                // Make the state changes smooth
                ParallelAnimation {
                    ColorAnimation { property: "color"; duration: 500 }
                    NumberAnimation { duration: 300; properties: "detailsOpacity,x,contentY,height,width" }
                }
            }
        }
    }

    // The actual list
    ListView {
        id: listView
        anchors.fill: parent
        model: RecipesModel {}
        delegate: recipeDelegate
    }
}







}
