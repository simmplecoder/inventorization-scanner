import QtQuick 2.0
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

import com.inventorization.communication 1.0

Item {
    id: borrowPageView

    BorrowServer
    {
        id: server
    }

    ColumnLayout {
        id: borrowLayout
        x: 213
        y: 99
        width: 200
        height: 282
        Layout.margins: 20

        Label {
            id: personIDLabel
            width: 100
            height: 20
            text: qsTr("Person ID")
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            font.pointSize: 14
        }

        Rectangle {
            id: rectangle
            width: lineEditLength
            height: 40
            color: "white"
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            TextInput {
                id: personIDEDit
                width: parent.width
                height: parent.height
                font.pixelSize: 20
                maximumLength: 8

            }
        }

        Label {
            id: itemIDLabel
            width: 100
            height: 20
            text: qsTr("Item ID")
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            font.pointSize: 14
        }

        Rectangle {
            width: lineEditLength
            height: 40
            color: "white"
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            TextInput {
                id: itemIDEDit
                width: parent.width
                height: parent.height
                font.wordSpacing: 5
                cursorVisible: false
                font.pixelSize: 20

                maximumLength: 8
            }
        }

        Label {
            id: borrowStatusLabel
            width: 100
            height: 20
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            font.pointSize: 14
        }

        Button {
            id: borrowItemButton
            width: 75
            height: 30
            text: "Borrow"
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            onClicked:
            {
                if (itemIDEDit.text.length != 0 && personIDEDit.text.length != 0)
                {
                    server.submitBorrowForm(personIDEDit.text, itemIDEDit.text)
                    borrowStatusLabel.text = server.getBorrowStatus()
                }
                else
                    borrowStatusLabel.text = "<font color=\"yellow\">Please specify both IDs</font>"
            }
        }

        Button {
            id: borrowBackButton
            width: 75
            height: 30
            text: "Back"
            onClicked: stack.pop()
            Layout.topMargin: 20
        }
    }
}
