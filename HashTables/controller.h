#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "mainmenu.h"
#include "simulationpresettings.h"

#include <QObject>

class Controller : public QObject{
    Q_OBJECT

public:
    explicit Controller(QObject *parent = nullptr);

private slots:
    void slotCreateSimulationPresettings();
    void slotBackToMenu();

private:
    MainMenu* mainMenu;
    SimulationPresettings* simulationPresettings;
};

#endif // CONTROLLER_H
