#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QObject>

#include <string>
#include <vector>

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

    auto borrowButton = engine.findChild<QObject*>("borrowItemButton");

//    new borrower{&app};
    return app.exec();
}
