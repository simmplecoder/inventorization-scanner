#include "returnserver.h"
#include <QString>
#include <QVariant>

ReturnServer::ReturnServer(QObject* target, QObject *parent) :
    target(target),
    QObject(parent)
{

}

void ReturnServer::returnPressed(const QString& str)
{
    //qDebug() << "the signal got to slot correctly";
    QVariant status = "Returned";

//    emit statusReady(QVariant::fromValue(status));
    QMetaObject::invokeMethod(target, "setReturnStatus", Q_ARG(QVariant, status));
}
