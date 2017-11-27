import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

ApplicationWindow {
    id: mainWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("Borrowment terminal")

//    signal submitReturnForm(string itemID)
//    signal returnStatusReady(string status)
//    function setReturnStatus(status)
//    {
//        console.log(status)
////        ReturnPage.returnStatus = status
//        returnStatusReady(status)
//    }

    property int lineEditLength: 120
    background: Rectangle
    {
        id: mainBackground
        color: "gray"
    }

    StackView
    {
        id: stack
        initialItem: returnPageComponent
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
