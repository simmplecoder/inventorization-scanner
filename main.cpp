#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QObject>
#include <QQuickWindow>

#include "borrower.h"
#include "returnserver.h"

//class borrower : public QObject
//{
//    Q_OBJECT

//    std::vector<std::string> personIDs;
//    std::vector<std::string> itemIDs;

//public:
//    borrower(QObject* parent = nullptr):
//        personIDs{"11111111", "22222222"},
//        itemIDs{"11111111", "22222222"}
//    {}

//public slots:

//};

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    QObject *topLevel = engine.rootObjects().value(0);
    QQuickWindow *window = qobject_cast<QQuickWindow *>(topLevel);
    QObject* returnStatusLabel = engine.findChild<QObject*>("returnStatusLabel");

    ReturnServer returner(returnStatusLabel);

    QObject::connect(window, SIGNAL(submitReturnForm(QString)), &returner, SLOT(returnPressed(QString)));
    //QObject::connect(&returner, SIGNAL(statusReady(QString)), returnStatusLabel, SIGNAL(onReturnStatusReady(QString)));
//    new borrower{&app};
    return app.exec();
}
