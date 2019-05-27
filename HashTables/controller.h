#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "mainmenu.h"
#include "simulationpresettings.h"
#include "simulationchainedhashtable.h"

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
    void slotAddElementToData(HashTableElement<int, QString>* element);

private:
    MainMenu* mainMenu;
    SimulationPresettings* simulationPresettings;
    SimulationChainedHashTable* simulationChainedHashTable;

    QVector<HashTableElement<int, QString>*> data;

private: //methods
    HashTableElement<int, QString>* getElementByIndex(int index);
};

#endif // CONTROLLER_H
