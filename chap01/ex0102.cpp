//ex0102.cpp
//Connecting a buttons's Clicked-Signal to Application's Quit-Slot

#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  QPushButton *button = new QPushButton("Quit");
  //Connect the button's "Clicked"-Signal to Application's quit() - Slot
  QObject::connect(button, SIGNAL(clicked()), &app, SLOT(quit()));
  button->show();
  return app.exec();
}
