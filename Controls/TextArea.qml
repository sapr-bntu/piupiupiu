// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Rectangle {
    id:textArea
    width :400; height:400
    color: yellow
   // property color fontColor: "white"
    //property alias textContent: textEdit.text
    Flickable {
        id: flickArea
        width: parent.width; height: parent.height
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
        //    color:  "red"
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
