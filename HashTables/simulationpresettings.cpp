#include "simulationpresettings.h"
#include "ui_simulationpresettings.h"

SimulationPresettings::SimulationPresettings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SimulationPresettings)
{
    ui->setupUi(this);
}

SimulationPresettings::~SimulationPresettings()
{
    delete ui;
}
