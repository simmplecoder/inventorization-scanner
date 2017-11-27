#include "connectionpool.h"
#include <stdexcept>
#include <QSqlError>

ConnectionPool::ConnectionPool()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("TEST");
    db.setUserName("root");
    db.setPassword("123");
    if (!db.open())
    {
        throw std::runtime_error{db.lastError().text().toStdString()};
    }
}

QSqlDatabase& ConnectionPool::get_instance()
{
    static ConnectionPool connection;
    return connection.db;
}
