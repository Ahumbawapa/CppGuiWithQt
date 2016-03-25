#include <QtWidgets>  // for Qt 5
//#include <QtGui>        // for Qt 4
#include "gotocelldialog.h"

GoToCellDialog::GoToCellDialog(QWidget *parent)
 :QDialog(parent)
{
    //...connects automatically any slots that follows the namingconvention (DOES NOT WORK in Qt5.5!!)
    //   on_objectName_signalName -> SIGNAL(textChanged(const QString &) -> SLOT(on_lineEdit_textChanged());
    setupUi(this);
    buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
    //Allow ONE upper- or lowercase letter, followed by one digit in the range
    //1 to 9, followed by zero,one or two digits each in range 0 to 9.
    QRegExp regExp("[A-Za-z][1-9][0-9]{0,2}");
    lineEdit->setValidator(new QRegExpValidator(regExp, this));

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
    //connect(lineEdit, SIGNAL(textChanged(const QString &)), this, SLOT(on_lineEdit_textChanged()));


}

void GoToCellDialog::on_lineEdit_textChanged()
{
    buttonBox->button(QDialogButtonBox::Ok)->setEnabled(lineEdit->hasAcceptableInput());
}
