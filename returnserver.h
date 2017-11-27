#ifndef RETURNSERVER_H
#define RETURNSERVER_H

#include <QObject>
#include <QVariant>
#include <QString>
#include <QQuickItem>

class ReturnServer : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QString returnStatus READ getReturnStatus WRITE setReturnStatus NOTIFY onReturnStatusChanged)
    QString returnStatus;
public:
    ReturnServer(QQuickItem* parent = nullptr);

signals:
    void onReturnStatusChanged(QString status);

public slots:
    void submitForm(const QString& itemID);
    QString getReturnStatus();
    void setReturnStatus(QString status);
};

#endif // RETURNSERVER_H
