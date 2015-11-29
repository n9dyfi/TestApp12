#include <QtGui/QApplication>
#include <QDeclarativeItem>
#include "qmlapplicationviewer.h"
#include "counter.h"

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QScopedPointer<QApplication> app(createApplication(argc, argv));
    Counter *counter;

    QmlApplicationViewer viewer;
    counter = new Counter;

    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(QLatin1String("qml/TestApp12/main.qml"));
    viewer.showExpanded();

    // get the QML root object for signal-slot connections
    QObject *qml = viewer.rootObject();

    // connect QML signals to counter slots
    QObject::connect(qml,SIGNAL(setValue(int)),counter,SLOT(setValue(int)));
    QObject::connect(qml,SIGNAL(increment()),counter,SLOT(increment()));
    QObject::connect(qml,SIGNAL(decrement()),counter,SLOT(decrement()));
    // connect counter signals to QML slots
    QObject::connect(counter,SIGNAL(valueChanged(int)),qml,SLOT(valueChanged(int)));

    counter->setValue(0);
    return app->exec();
}
