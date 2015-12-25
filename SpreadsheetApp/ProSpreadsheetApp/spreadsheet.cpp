#include "spreadsheet.h"
#include <QDebug>

Spreadsheet::Spreadsheet(QObject *parent) :
    QObject(parent)
{
}


bool Spreadsheet::findNext(const QString &what, Qt::CaseSensitivity cs)
{
    return false;
}


bool Spreadsheet::findPrevious(const QString &what, Qt::CaseSensitivity cs)
{
    return false;
}

bool Spreadsheet::setCurrentCell(int row, int column)
{
    qDebug() << QString("Spreadsheet::setCurrentCell[%1, %2]").arg(row).arg(column);
    return false;
}
