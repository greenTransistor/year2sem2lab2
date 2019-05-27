#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "mainmenu.h"
#include "simulationpresettings.h"
#include "simulationchainedhashtable.h"

#include <QQueue>
#include <QObject>

class Controller : public QObject{
    Q_OBJECT

public:
    explicit Controller(QObject *parent = nullptr);

private slots:
    void slotCreateSimulationPresettings();
    void slotCreateSimulationChainedHashTable();
    void slotBackToMenuFromSimulationPresettings();
    void slotBackToMenuFromSimulationChainedHashTable();
    void slotAddElementToData();
    void slotNextInsertedElementFromSimulationChainedHashTable();

private:
    MainMenu* mainMenu;
    SimulationPresettings* simulationPresettings;
    SimulationChainedHashTable* simulationChainedHashTable;

    QQueue<HashTableElement<int, QString>*> data;

private: //methods
    void addElementToData(HashTableElement<int, QString>* element);
};

#endif // CONTROLLER_H
