#include "controller.h"

#include "ui_mainmenu.h"
#include "ui_simulationpresettings.h"

Controller::Controller(QObject *parent) : QObject(parent){

    mainMenu = new MainMenu();
    connect(mainMenu->ui->simulationButton, SIGNAL(clicked()), this, SLOT(slotCreateSimulationPresettings()));

    mainMenu->show();
}

void Controller::slotCreateSimulationPresettings()
{
    mainMenu->hide();

    simulationPresettings = new SimulationPresettings();
    connect(simulationPresettings->ui->backToMenuButton, SIGNAL(clicked()), this, SLOT(slotBackToMenu()));

    simulationPresettings->show();

}

void Controller::slotBackToMenu()
{
    delete simulationPresettings;
    mainMenu->show();
}
