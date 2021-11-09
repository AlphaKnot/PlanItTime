import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    width: 640 // set screen dimensions
    height: 480
    visible: true
    title: qsTr("PlanitTime")

    //ADD FONTS
    // WHY IS THIS FONT NOT LOADING AHHHHHH
    FontLoader{
        id: fontARCADECLASSIC
        source:"qrc:/fonts/ARCADECLASSIC.TFF"
    }

    // dynamic time and date
    Timer{
        interval: 1000 // 1 second
        running: true
        repeat: true
        onTriggered: {
            time.text = Qt.formatDateTime(new Date(), "hh:mm:ss")
            date.text = Qt.formatDateTime(new Date(), "dddd dd MMM")
        }
    }



    Rectangle{
        id: rectDateTime
        // getting screen dimensions
        width: parent.width
        height: parent.height
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        // color background
        color:"#16283b"

        //Time
        Rectangle{
            id: rectTime
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 25
            height: 100
            color:"transparent"

            Text{
                id: time
                text: qsTr("10:25")
                anchors.centerIn: parent
                color:"white"
                font.pointSize: 80
                font.family: fontARCADECLASSIC.name
            }
        }

        Rectangle{
            id: rectDate
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top:rectTime.bottom
            width: 60
            color: "transparent"

            Text {
                id: date
                text: qsTr("November 8 2021")
                anchors.centerIn: parent
                color:"white"
                font.pointSize: 25
                font.family: fontARCADECLASSIC.name
            }
        }

    }
}
