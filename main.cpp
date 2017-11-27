#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QObject>
#include <QQuickWindow>

#include "returnserver.h"
#include "borrowserver.h"

#include "connectionpool.h"
#include <QSqlError>

//void initDatabaseConnection()
//{
//    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
//    db.setHostName("bigblue");
//    db.setDatabaseName("flightdb");
//    db.setUserName("acarlson");
//    db.setPassword("1uTbSbAs");
//    bool ok = db.open();
//}

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    qmlRegisterType<ReturnServer>("com.inventorization.communication", 1, 0, "ReturnServer");
    qmlRegisterType<BorrowServer>("com.inventorization.communication", 1, 0, "BorrowServer");
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("TEST");
    db.setUserName("root");
    db.setPassword("123");
    if (!db.open())
    {
        throw std::runtime_error{db.lastError().text().toStdString()};
    }

    return app.exec();
}
