#ifndef BORROWER_H
#define BORROWER_H

#include <QObject>

class Borrower : public QObject
{
    Q_OBJECT
public:
    explicit Borrower(QObject *parent = nullptr);

signals:

public slots:
    void borrowPressed(const QString& str);
};

#endif // BORROWER_H
