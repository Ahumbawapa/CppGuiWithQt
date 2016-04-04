#include <QtWidgets>

#include "hexspinbox.h"

HexSpinBox::HexSpinBox(QWidget *parent)
    :QSpinBox(parent)
{
    setRange(0, 255);
    validator = new QRegExpValidator(QRegExp("[0-9A-Fa-f]{1,8}"), this);

}

/*
 * called by QSpinBox to see if entered text is valid so far
 * possible results:
 * Invalid, Intermediate, Acceptable
 */
QValidator::State HexSpinBox::validate(QString &text, int &pos) const
{
    return validator->validate(text, pos);
}


QString HexSpinBox::textFromValue(int value) const
{
    //converts integer value to string
    //here hexadecimal in Uppercase
    return QString::number(value, 16).toUpper();
}

int HexSpinBox::valueFromText(const QString &text) const
{
    bool ok;
    //toInt returns 0 and set ok to false if the conversion is not possible
    return text.toInt(&ok, 16);
}


