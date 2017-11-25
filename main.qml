import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Borrowment terminal")

    property int lineEditLength: 120
    background: Rectangle
    {
        id: mainBackground
        color: "gray"
    }

    StackView
    {
        id: stack
        initialItem: homePageComponent
    }

    Component
    {
        id: homePageComponent
        HomePage{}
    }

    Component
    {
        id: borrowPageComponent
        BorrowPage{}
    }

    Component
    {
        id: returnPageComponent
        ReturnPage{}
    }
}
