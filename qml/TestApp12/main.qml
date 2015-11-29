import QtQuick 1.1
import com.nokia.meego 1.0

PageStackWindow {
    id: appWindow

    // slot that can be connected to C++ signal
    signal valueChanged(int value);

    // signals that can be connected to C++ slots
    signal setValue(int value);
    signal increment();
    signal decrement();

    property alias counterValue: mainPage.counterValue

    initialPage: mainPage

    MainPage {
        id: mainPage
    }

    onValueChanged: {
        counterValue = value;
    }

    ToolBarLayout {
        id: commonTools
        visible: true
        ToolIcon {
            platformIconId: "toolbar-view-menu"
            anchors.right: (parent === undefined) ? undefined : parent.right
            onClicked: (myMenu.status === DialogStatus.Closed) ? myMenu.open() : myMenu.close()
        }
    }

    Menu {
        id: myMenu
        visualParent: pageStack
        MenuLayout {
            MenuItem { text: qsTr("Sample menu item") }
        }
    }
}
