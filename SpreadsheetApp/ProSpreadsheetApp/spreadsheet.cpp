#include <QtWidgets> //for Qt >= 5.0
//#include <QtGui>      //for Qt > 5.0
#include "cell.h"
#include "spreadsheet.h"

Spreadsheet::Spreadsheet(QWidget *parent) :
    QTableWidget(parent)
{
    autoRecalc = true;

    //normally QTableWidget automatically creates a QTableWidgetItem to hold text
    //here we wanted cell-items to be created
    setItemPrototype(new Cell);
    setSelectionMode(ContiguousSelection);//allows single rectangular selection

    connect(this, SIGNAL(itemChanged(QTableWidgetItem *)),
            this, SLOT(somethingChanged()));

    clear();
}

//resize table and set column headings
void Spreadsheet::clear()
{
    setRowCount(0);
    setColumnCount(0);

    setRowCount(RowCount);
    setColumnCount(ColumnCount);

    for (int i = 0; i < ColumnCount; ++i)
    {
        QTableWidgetItem *item = new QTableWidgetItem;
        item->setText(QString(QChar('A' + i)));
        setHorizontalHeaderItem(i, item);
    }

    setCurrentCell(0,0);
}

Cell *Spreadsheet::cell(int row, int column) const
{
    return static_cast<Cell *> (item(row,column));
}

QString Spreadsheet::text(int row, int column) const
{
    Cell *c = cell(row, column);
    if(c)
    {
        return c->text();
    }
    else
    {
        return "";
    }
}

QString Spreadsheet::formula(int row, int column) const
{
    Cell *c = cell(row, column);
    if(c)
    {
        return c->formula();
    }
    else
    {
        return "";
    }
}

void Spreadsheet::setFormula(int row, int column, const QString &formula)
{
    Cell *cell = cell(row, column);
    if(!c)
    {
        c = new Cell;
        setItem(row, column, c);
    }

    c->setFormula(formula);
}

QString Spreadsheet::currentLocation() const
{
    return QChar('A' + currentColumn()) + QString::number(currentRow() + 1);
}

QString Spreadsheet::currentFormula() const
{
    return formula(currentRow(), currentColumn());
}

void Spreadsheet::somethingChanged()
{
    if(autoRecalc)
        recalculate();

    emit modified();
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
