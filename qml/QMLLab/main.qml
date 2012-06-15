import QtQuick 1.1
import Qt 4.7


Rectangle {
    id: rectangle1
    width: 800
    height: 640
    color: "#FF4E4E4E"


    Item
    {
        id: itemForList
        width: 484
        height: 120
        x: 5
        y: 510

      /*  ListView {
            width: 484
            height: 120
            id: listViewPath
            anchors.fill: parent
            model: FileModel {}
            delegate: Rectangle
            {

            color: "lightblue"
            width: 484; height: 25
            Text {
                id: textItem
                anchors.centerIn: parent
               // font.pointSize: 10

                text: number+'. ' + name
            //  text: filePath
            }

            MouseArea {
                id: mouseArea
                anchors.fill: parent
                onDoubleClicked: {

                   listViewPath.currentIndex=number-1


                   // edit.text = window.la(listViewPath.model.get(listViewPath.currentIndex).location)
                  //  edit.text = window.la();
                  //  window.la(edit.text);
                  //  window.load(edit.text);
                 //   window.WhereFile(edit.text);

                   edit555.text = window.WhereFile(edit555.text)

                    console.log("reading");


                }
                onClicked: {

                    listViewPath.currentIndex=number-1
                }
            }

        }
                //contactDelegate
            highlight: Rectangle { color: "lime"; radius: 5 }


        }*/


    ListView {
        id: listViewTree
        width: 285
        height: 120
        x: 1000
        y: 510

       anchors.fill: parent

        model: VisualDataModel {
            model: dirModel
           // Path: "D:/"

            delegate: Rectangle {

                color: "lightblue"
                width: 285; height: 25
                Text { text: filePath }

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        if (model.hasModelChildren)
                            listViewTree.model.rootIndex = listViewTree.model.modelIndex(index)
                        else
                        {
                            console.log(filePath);
                            console.log("test");

//                            parent.
                            edit555.text = window.WhereFile(filePath);


                         //   edit.text = window.la();
                        //listViewPath.model.append({"number": window.kol(listViewPath.model.count), "name":window.title(filePath),"location":filePath})
                          //  edit.text = window.WhereFile(edit.text)


                        }



                    }
                }
            }
        }
    }
    }











    GreyButton {
        id: mgreybutton8
        x:515
        y:310
        text: "Clear TextEdit"
        onClicked:{
            edit555.text = ""


         listViewTree.model.setRootPath(dir);
      //listViewTree.model.index("D:/107528");

               }
    }




    GreyButton {
        id: unzipbutton
        x:690
        y:310
        text: "Unzip *.chm"
        onClicked:{
            window.FunctionPIU()

            console.log("ata-ta")
          //  edit555.text = window.FunctionOPEN()
          //  model.index("D:/107528");

                  }
               }

    GreyButton {
        id: mgreybutton2
        x:690
        y:350
        anchors.left: rectangle1.anchors.left
        anchors.right:rectangle1.anchors.right
        text: "Delete *.htm"
        onClicked:
        window.FunctionPIUPIUPIU()


                        }

    GreyButton {
        id: mgreybutton3
        x:690
        y:390
        anchors.left: rectangle1.anchors.left
        anchors.right:rectangle1.anchors.right
        text: "Save As"
        onClicked:
         window.savik(edit555.text);
                }

      GreyButton {
        id: mgreybutton4
        x:690
        y:430
        anchors.left: rectangle1.anchors.left
        anchors.right:rectangle1.anchors.right
        text: "Open *.htm"
        onClicked:
                {
            edit555.text = window.FunctionMDE();
                }
                   }

      GreyButton {
          id: mgreybutton5
          x:690
          y:470
          anchors.left: rectangle1.anchors.left
          anchors.right:rectangle1.anchors.right
          text: "Exit"
          onClicked:
          {
              Qt.quit();
           //   window.close()
          }

                  }

      Rectangle {
          id:textArea
         //  color: "#FF4E4E4E"
         color: "white"
         border.color: "black"
         border.width: 3
         radius: 5
         anchors.left: rectangle1.anchors.left
         anchors.right:rectangle1.anchors.right
          x: 7
          y: 1
          width :484; height:480 //650

          Rectangle {
              color: "lightblue"
              anchors.fill: parent
              anchors.margins: 5

              BorderImage {
                  id: startHandle
                  source: "../../pics/startHandle.sci"
                  opacity: 0.0
                  width: 10
                  x: edit555.positionToRectangle(edit555.selectionStart).x - flick.contentX-width
                  y: edit555.positionToRectangle(edit555.selectionStart).y - flick.contentY
                  height: edit555.positionToRectangle(edit555.selectionStart).height
              }

              BorderImage {
                  id: endHandle
                  source: "../../pics/endHandle.sci"
                  opacity: 0.0
                  width: 10
                  x: edit555.positionToRectangle(edit555.selectionEnd).x - flick.contentX
                  y: edit555.positionToRectangle(edit555.selectionEnd).y - flick.contentY
                  height: edit555.positionToRectangle(edit555.selectionEnd).height
              }



              Flickable {
                  id: flick

                  anchors.fill: parent
                  contentWidth: edit555.paintedWidth
                  contentHeight: edit555.paintedHeight
                  interactive: true
                  clip: true

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
                      id: edit555
                      width: flick.width
                      height: flick.height
                      focus: true
                      wrapMode: TextEdit.Wrap


                      onCursorRectangleChanged: flick.ensureVisible(cursorRectangle)

                      text: "     <center><h2>ОБУЧЕНИЕ ДЛЯ СЛАБЫХ:</h2>"
                          +"<p><b><center>ВЫ НЕ ЗНАЕТЕ КАК ЮЗАТЬ СКРОЛЛ?  МЫ ВАС НАУЧИМ!"
                          +"<p><b><center>ЧТОБЫ ПРОЛИСТАТЬ ДОКУМЕНТ ВНИЗ - ВАМ НАДО ПРОКРУТИТЬ КОЛЕСО МЫШИ НА СЕБЯ."
                          +"<p><b><center>ЧТОБЫ ПРОЛИСТАТЬ ДОКУМЕНТ ВНИЗ - ВАМ НАДО ПРОКРУТИТЬ КОЛЕСО МЫШИ ОТ СЕБЯ."
                          +"<p><b><center>ИЛИ ЖЕ ПРОСТО НАЖМИТЕ НА ДОКУМЕНТ И ТАЩИТЕ В НЕОБХОДИМУЮ СТОРОНУ!"
                          +"<p><b><center>СПАСИБО ЗА ВНИМАНИЕ! (c) 107528"
                        font.pixelSize: 15

                      MouseArea {
                          property string drag: ""
                          property int pressPos

                          x: -startHandle.width
                          y: 0
                          width: parent.width+startHandle.width+endHandle.width
                          height: parent.height



                          onClicked: {
                              if (textArea.state == "") {
                                  edit555.cursorPosition = edit555.positionAt(mouse.x+x,mouse.y+y);
                                  if (!edit555.focus)
                                      edit555.focus = true;
                                  edit555.openSoftwareInputPanel();
                              }
                          }

                          function hitHandle(h,x,y) {
                              return x>=h.x+flick.contentX && x<h.x+flick.contentX+h.width && y>=h.y+flick.contentY && y<h.y+flick.contentY+h.height
                          }

//

                          onPositionChanged: {
                              if (textArea.state == "selection" && drag != "") {
                                  if (drag == "start") {
                                      var pos = edit555.positionAt(mouse.x+x+startHandle.width/2,mouse.y+y);
                                      var e = edit555.selectionEnd;
                                      if (e < pos)
                                          e = pos;
                                      edit555.select(pos,e);
                                  } else if (drag == "end") {
                                      var pos = edit555.positionAt(mouse.x+x-endHandle.width/2,mouse.y+y);
                                      var s = edit555.selectionStart;
                                      if (s > pos)
                                          s = pos;
                                      edit555.select(s,pos);
                                  }
                              }
                          }
                      }
                  }
              }




                    }

          states: [
              State {
                  name: "selection"
                  PropertyChanges { target: startHandle; opacity: 1.0 }
                  PropertyChanges { target: endHandle; opacity: 1.0 }
              },
              State {
                  name: "menu"
                  PropertyChanges { target: startHandle; opacity: 0.5 }
                  PropertyChanges { target: endHandle; opacity: 0.5 }
                  PropertyChanges { target: menu; opacity: 1.0 }
              }
          ]

            }

// This example illustrates expanding a list item to show a more detailed view.
//glavnoe okno
    Rectangle {
    id: page
    x:520
    y:0
    width: 285; height: 300
    color: "black"
//    anchors.horizontalCenter: parent.horizontalCenter
//    anchors.verticalCenter: parent.verticalCenter
//    anchors.horizontalCenterOffset: 250
//    anchors.verticalCenterOffset: -165

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
                    //source: picture
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

                    opacity: flick.atYBeginning ? 0 : 1
                }

                Image {
                    anchors { right: flick.right; bottom: flick.bottom }

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
