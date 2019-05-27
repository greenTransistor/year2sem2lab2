#include "simulationchainedhashtable.h"
#include "ui_simulationchainedhashtable.h"

SimulationChainedHashTable::SimulationChainedHashTable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SimulationChainedHashTable)
{
    ui->setupUi(this);
}

SimulationChainedHashTable::~SimulationChainedHashTable()
{
    delete ui;
}
