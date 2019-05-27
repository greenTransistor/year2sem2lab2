#include "simulationchainedhashtable.h"
#include "ui_simulationchainedhashtable.h"

SimulationChainedHashTable::SimulationChainedHashTable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SimulationChainedHashTable),
    hashTable(ChainedHashTable<int, QString>(HASHTABLE_SIZE))
{
    ui->setupUi(this);
    ui->tableWidget->setRowCount(HASHTABLE_SIZE);
}

SimulationChainedHashTable::~SimulationChainedHashTable()
{
    delete ui;
}
