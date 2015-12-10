#include <QtWidgets>
#include "finddialog.h"


FindDialog::FindDialog(QWidget *parent)
 : QDialog(parent) //pass parent parameter to base class constructor
{
    //create child widgets
    label = new QLabel(tr("Find &what:"));//tr mark string literals for translation
    lineEdit = new QLineEdit;
    label->setBuddy(lineEdit);

    caseCheckBox = new QCheckBox(tr("Match &case"));//& indicates shortcut keys
    backwardCheckBox = new QCheckBox(tr("Search &backward"));

    findButton = new QPushButton(tr("&Find"));
    findButton->setDefault(true);
    findButton->setEnabled(false);

    closeButton = new QPushButton(tr("Close"));

    //call function enableFindbutton whenever text changed in lineEdit
    connect(lineEdit, SIGNAL(textChanged(const QString &)), this, SLOT(enableFindButton(const QString &)));
    //call function / SLOT findClicked when user clicks findButton
    connect(findButton, SIGNAL(clicked()), this, SLOT(findClicked()));
    //close()-Slot is inherited from QWidget
    connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));

    QHBoxLayout *topLeftLayout = new QHBoxLayout;
    topLeftLayout->addWidget(label);
    topLeftLayout->addWidget(lineEdit);

    QVBoxLayout *leftLayout = new QVBoxLayout;
    leftLayout->addLayout(topLeftLayout);
    leftLayout->addWidget(caseCheckBox);
    leftLayout->addWidget(backwardCheckBox);

    QVBoxLayout *rightLayout = new QVBoxLayout;
    rightLayout->addWidget(findButton);
    rightLayout->addWidget(closeButton);
    rightLayout->addStretch();//add a spacer

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);
    setLayout(mainLayout);//sublayouts are reparented to become children of dialog

    setWindowTitle(tr("Find"));
    setFixedHeight(sizeHint().height());//QWidget::sizeHint() return a ideal size

}

void FindDialog::findClicked()
{
    QString text = lineEdit->text();
    Qt::CaseSensitivity cs = caseCheckBox->isChecked() ? Qt::CaseSensitive : Qt::CaseInsensitive;

    if(backwardCheckBox->isChecked())
        emit findPrevious(text, cs);
    else
        emit findNext(text, cs);
}

void FindDialog::enableFindButton(const QString &text)
{
    findButton->setEnabled(!text.isEmpty());
}

