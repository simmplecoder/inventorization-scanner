#ifndef CONNECTIONPOOL_H
#define CONNECTIONPOOL_H

#include <QSqlDatabase>

class ConnectionPool
{
    QSqlDatabase db;
public:
    ConnectionPool(const ConnectionPool&) = delete;
    ConnectionPool(ConnectionPool&&) = delete;

    ConnectionPool& operator=(const ConnectionPool&) = delete;
    ConnectionPool& operator=(ConnectionPool&&) = delete;

    static QSqlDatabase& get_instance();

private:
    ConnectionPool();
};

#endif // CONNECTIONPOOL_H
