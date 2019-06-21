#include "controller.h"

#include "ui_mainmenu.h"
#include "ui_simulationpresettings.h"
#include "ui_simulationchainedhashtable.h"

Controller::Controller(QObject *parent) : QObject(parent){

    mainMenu = new MainMenu();
    connect(mainMenu->ui->simulationButton, SIGNAL(clicked()), this, SLOT(slotCreateSimulationPresettings()));

    mainMenu->show();
}

void Controller::slotCreateSimulationPresettings()
{
    mainMenu->hide();

    simulationPresettings = new SimulationPresettings();
    connect(simulationPresettings->ui->backToMenuButton, SIGNAL(clicked()), this, SLOT(slotBackToMenuFromSimulationPresettings()));
    connect(simulationPresettings->ui->startButton, SIGNAL(clicked()), this, SLOT(slotCreateSimulationChainedHashTable()));
    connect(simulationPresettings->ui->addButton, SIGNAL(clicked()), this, SLOT(slotAddElementToData()));

    simulationPresettings->show();

}

void Controller::slotCreateSimulationChainedHashTable()
{
    simulationPresettings->hide();
    Entity entity = Entity(simulationPresettings->ui->hashTableTypeComboBox->currentIndex());

    simulationChainedHashTable = new SimulationChainedHashTable(entity);
    connect(simulationChainedHashTable->ui->backToMenuButton, SIGNAL(clicked()), this, SLOT(slotBackToMenuFromSimulationChainedHashTable()));
    connect(simulationChainedHashTable->ui->nextInsertButton, SIGNAL(clicked()), this, SLOT(slotNextInsertedElementFromSimulationChainedHashTable()));

    simulationChainedHashTable->show();
}

void Controller::slotBackToMenuFromSimulationPresettings()
{
    delete simulationPresettings;
    mainMenu->show();
}

void Controller::slotBackToMenuFromSimulationChainedHashTable()
{
    delete simulationChainedHashTable;
    mainMenu->show();
}

void Controller::slotAddElementToData()
{
    HashTableElement<int, QString>* element = simulationPresettings->getHashTableElement();
    addElementToData(element);
    simulationPresettings->clearInputFields();
}

void Controller::addElementToData(HashTableElement<int, QString> *element)
{
    data.enqueue(element);
}

void Controller::slotNextInsertedElementFromSimulationChainedHashTable()
{
    if (data.empty()){
        simulationChainedHashTable->ui->curInsertElement->setText("Nothing to insert!");
        return;
    }
    simulationChainedHashTable->curInsertedElement(data.dequeue());
}
