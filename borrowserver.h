#ifndef BORROWER_H
#define BORROWER_H

#include <QObject>
#include <QQuickItem>
#include <QString>

class BorrowServer : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QString borrowStatus READ getBorrowStatus WRITE setBorrowStatus NOTIFY onBorrowStatusChanged)
    QString borrowStatus;
public:
    explicit BorrowServer(QQuickItem *parent = nullptr);

signals:
    void onBorrowStatusChanged(QString newStatus);
public slots:
    QString getBorrowStatus();
    void setBorrowStatus(const QString& status);
    void submitBorrowForm(const QString& personID, const QString& itemID);

private:
//    QString findLab(const QString& personID);
//    bool userExists(const QString& personID);
//    bool isBorrowed(const QString& itemID);
//    bool itemExists(const QString& itemID);
};

#endif // BORROWER_H
