#include "sortdialog.h"
#include "ui_sortdialog.h"

SortDialog::SortDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SortDialog)
{
    ui->setupUi(this);

    ui->secondaryGroupBox->hide();
    ui->tertiaryGroupBox->hide();

    // making the dialog not-resizeable by the user
    layout()->setSizeConstraint(QLayout::SetFixedSize);

    setColumnRange('A', 'Z');
}

SortDialog::~SortDialog()
{
    delete ui;
}

void SortDialog::setColumnRange(QChar first, QChar last)
{
    ui->primaryColumnCombo->clear();
    ui->secondaryColumnCombo->clear();
    ui->tertiaryColumnCombo->clear();

    ui->secondaryColumnCombo->addItem(tr("None"));
    ui->tertiaryColumnCombo->addItem(tr("None"));
    //set primary's comboBox minimum size to secondary combobox ideal size
    ui->primaryColumnCombo->setMinimumSize( ui->secondaryColumnCombo->sizeHint());

    QChar ch = first;
    while(ch <= last)
    {
        ui->primaryColumnCombo->addItem(QString(ch));
        ui->secondaryColumnCombo->addItem(QString(ch));
        ui->tertiaryColumnCombo->addItem(QString(ch));

        ch = ch.unicode() + 1;
    }
}
