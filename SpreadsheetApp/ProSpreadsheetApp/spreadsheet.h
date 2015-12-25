#ifndef SPREADSHEET_H
#define SPREADSHEET_H

#include <QObject>

class Spreadsheet : public QObject
{
    Q_OBJECT
public:
    explicit Spreadsheet(QObject *parent = 0);

signals:

public slots:
    bool findNext(const QString& what, Qt::CaseSensitivity cs);
    bool findPrevious(const QString& what, Qt::CaseSensitivity cs);
    bool setCurrentCell(int row, int column);

};

#endif // SPREADSHEET_H
