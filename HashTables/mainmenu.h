#ifndef MAINMENU_H
#define MAINMENU_H

//#include "controller.h"
#include <QMainWindow>

namespace Ui {
class MainMenu;
}

class Controller;

class MainMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = nullptr);
    ~MainMenu();

private:
    Ui::MainMenu *ui;

public:
    friend Controller;
};

#endif // MAINMENU_H
