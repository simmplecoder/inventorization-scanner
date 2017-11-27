import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2

Item {
    id: returnPageView
    property alias returnStatus: returnStatusLabel.text

    ColumnLayout {
        id: returnPageMenu
        x: 213
        y: 99
        width: 200
        height: 282
        Layout.margins: 20

        Label {
            id: itemIDLabel
            text: "Item ID"
            width: 100
            height: 20
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            font.pointSize: 14
        }

        Rectangle {
            width: lineEditLength
            height: 40
            color: "white"
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            TextInput {
                id: itemIDEdit
                width: parent.width
                height: parent.height
                font.pixelSize: 20
                maximumLength: 8
            }


        }

        Label
        {
            id: returnStatusLabel
            objectName: "returnStatusLabel"
            function setReturnStatus(status) {
                console.log("set return status to " + status)
                ReturnPage.returnStatus = status
            }
            text: "empty"
            width: 100
            height: 20
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            font.pointSize: 14

        }

        Button {
            id: returnItemButton
            width: 75
            height: 30
            text: "Return the Item"
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            onClicked:  submitReturnForm(itemIDEdit.text)
        }

        Button {
            id: backButton
            width: 75
            height: 30
            text: "Back"
            onClicked: stack.pop();
        }
    }
}
