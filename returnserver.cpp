#include "returnserver.h"
#include <QString>
#include <QVariant>

ReturnServer::ReturnServer(QQuickItem* parent) :
    QQuickItem(parent),
    returnStatus("Not set")
{

}

void ReturnServer::submitForm(const QString &itemID)
{
    if (itemID == "11111111")
    {
        returnStatus = "Returned!";
    }
    else
    {
        returnStatus = "Not Returned!";
    }
}

void ReturnServer::setReturnStatus(QString status)
{
    returnStatus = status;
}

QString ReturnServer::getReturnStatus()
{
    return returnStatus;
}
