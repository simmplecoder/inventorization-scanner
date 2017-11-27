#ifndef RETURNSERVER_H
#define RETURNSERVER_H

#include <QObject>
#include <QVariant>
#include <QString>
#include <QQuickWindow>

class ReturnServer : public QObject
{
    Q_OBJECT

    QObject* target;
public:
    ReturnServer(QObject* target, QObject* parent = nullptr);

public slots:
    void returnPressed(const QString& str);
};

#endif // RETURNSERVER_H
