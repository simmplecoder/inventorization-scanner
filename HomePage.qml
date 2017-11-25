import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2

Item {
    id: homePageView

    ColumnLayout {
        id: columnLayout
        x: 158
        y: 59
        width: 324
        height: 350

        Button {
            id: button
            text: qsTr("Borrow")
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Layout.preferredHeight: 40
            Layout.preferredWidth: 100
            onClicked: stack.push(borrowPageComponent)
        }

        Button {
            id: button1
            text: qsTr("Return")
            Layout.preferredHeight: 40
            Layout.preferredWidth: 100
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            onClicked: stack.push(returnPageComponent)
        }
    }
}
