import QtQuick 2.10
//import QtQuick.Controls 2.3

Image {
    property int id: 0
    property int tipo: 0
    property string imagem: ""

    source: imagem
    visible: true
    width: 10
    height: 10
    MouseArea{
        anchors.fill: parent
        cursorShape: Qt.PointingHandCursor
        onClicked: {
            var tmp = Qt.createComponent("tooltip.qml");
            var t;
            switch(tipo){
                case 0: t = "comum"; break;
                case 1: t = "patógeno"; break;
                case 2: t = "macrófago"; break;
                case 3: t = "neutrófilo"; break;
                case 4: t = "linfócito"; break;
            }

            tmp.createObject(this,{"id":id,"tipo": t,"imagem":parent.source});
        }
    }
}
