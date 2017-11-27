#include "borrowserver.h"
#include <QDebug>
#include <QSqlQuery>
#include <QDate>
#include <random>
#include <QSqlError>
#include "commonqueries.h"

BorrowServer::BorrowServer(QQuickItem *parent) : QQuickItem(parent)
{}

void BorrowServer::submitBorrowForm(const QString& personID, const QString& itemID)
{
    if (!userExists(personID))
    {
        borrowStatus = "<font color=\"yellow\">Invalid userID</font>";
        return;
    }

    if (!itemExists(itemID))
    {
        borrowStatus = "<font color=\"yellow\">Invalid itemID</font>";
        return;
    }

    if (isBorrowed(itemID))
    {
        borrowStatus = "<font color=\"red\">Already borrowed</font>";
        return;
    }

    auto ownerLab = findOwnerLab(itemID);
    auto associatedLab = findAssociatedLab(personID);
    if (ownerLab != associatedLab)
    {
        borrowStatus = "<font color=\"red\">Incorrect lab-owner</font>";
        return;
    }


    auto itemPrivelege = findItemPrivelege(itemID);
    auto personPrivelege = findPersonPrivelege(personID);

    if (itemPrivelege.toInt() > personPrivelege.toInt())
    {
        borrowStatus = "<font color=\"red\">Insufficient privelege</font>";
        return;
    }

    auto lab = findAssociatedLab(personID);
    QString insertBorrowingQuery =
            QString("INSERT INTO "
                    "BORROWING (user_id, lab_id, item_id, returned) VALUES "
                    " (%1 , %2 , %3 , %4)").arg(personID, lab, itemID, "false");
    QSqlQuery insertionQuery(insertBorrowingQuery);
    if (insertionQuery.lastError().type() != QSqlError::NoError)
    {
        throw std::runtime_error{insertionQuery.lastError().text().toStdString()};
    }

    borrowStatus = "<font color=\"green\">Borrowed successfully</font>";
}

void BorrowServer::setBorrowStatus(const QString& status)
{
    borrowStatus = status;
}

QString BorrowServer::getBorrowStatus()
{
    return borrowStatus;
}
