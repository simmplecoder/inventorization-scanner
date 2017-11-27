#include "returnserver.h"
#include <QString>
#include <QVariant>
#include <QSqlQuery>

#include "commonqueries.h"

ReturnServer::ReturnServer(QQuickItem* parent) :
    QQuickItem(parent),
    returnStatus("Not set")
{

}

void ReturnServer::submitForm(const QString &itemID)
{
//    QString returnQuery = QString("SELECT COUNT(*) "
//                                  "  FROM BORROWING"
//                                  "  WHERE ID=%1 AND returned=false").arg(itemID);
//    QSqlQuery query(returnQuery);
//    query.next(); //move once because dumb design
//    int match_count = query.value(0).toInt();

   if (!itemExists(itemID))
   {
       returnStatus = "<font color=\"red\">Item doesn't exist!</font>";
       return;
   }

    if (!isBorrowed(itemID))
    {
        returnStatus = "<font color=\"red\">Item is not borrowed!</font>";
        return;
    }

    returnStatus = "<font color=\"green\">returned!</font>";
    QString returnQueryStr = QString("UPDATE BORROWING SET returned=true WHERE item_id=%1").arg(itemID);
    QSqlQuery returnQuery(returnQueryStr);
    if (returnQuery.lastError().type() != QSqlError::NoError)
    {
        throw std::runtime_error{returnQuery.lastError().text().toStdString()};
    }
}

//bool ReturnServer::isBorrowed(const QString &itemID)
//{
//    QString countPersonQuery = QString("SELECT COUNT(*) FROM BORROWING WHERE id=%1 AND returned=false").arg(itemID);
//    QSqlQuery existsQuery(countPersonQuery);
//    if (!existsQuery.exec())
//    {
//        throw std::runtime_error{existsQuery.lastError().text().toStdString()};
//    }
//    existsQuery.next();
//    return existsQuery.value(0).toInt() != 0;
//}

void ReturnServer::setReturnStatus(QString status)
{
    returnStatus = status;
}

QString ReturnServer::getReturnStatus()
{
    return returnStatus;
}
