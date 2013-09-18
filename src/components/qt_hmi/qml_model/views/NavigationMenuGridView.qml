import QtQuick 2.0
import "../controls"
import "../models"

Item {
    anchors.fill: parent

    MenuGridView {
        anchors.centerIn: parent
        id: navMenuGridView
        model: NavigationMenuModel {}

        LongOvalBtn {
            id: lob
            visible: false
        }

        width: 3*lob.width
        height: 2*lob.height

        columns: 3
        rows: 2

        delegate: Item {
            id: cell
            width: button.width
            height: button.height

            LongOvalBtn {
                id: button
                text: title
                pixelSize: 20
                dest: qml
                anchors.centerIn: parent
            }
        }
    }

    Text{
        id: closeText
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 1/5 * contentLoader.height
        text: "CLOSE"
        color: "#1d81d5"
        font.pixelSize: 25
        MouseArea {
          anchors.fill: parent
          onClicked: {
              contentLoader.go("./views/NavigationNoRouteGridView.qml")
            }
        }

    }
}
