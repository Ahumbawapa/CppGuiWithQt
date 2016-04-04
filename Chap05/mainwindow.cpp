#include "mainwindow.h"
#include "hexspinbox.h"
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    HexSpinBox *hsb = new HexSpinBox(this);

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(hsb);

    this->setLayout(layout);
}

MainWindow::~MainWindow()
{

}
