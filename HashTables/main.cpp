#include "mainmenu.h"
#include "controller.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Controller* controller = new Controller();
//    MainMenu w;
//    w.show();

    return a.exec();
}
