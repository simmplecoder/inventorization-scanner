#include "borrower.h"
#include <QDebug>

Borrower::Borrower(QObject *parent) : QObject(parent)
{

}

void Borrower::borrowPressed(const QString& str)
{
    //qDebug() << "the signal got to slot correctly";

}
