#ifndef SIMULATIONCHAINEDHASHTABLE_H
#define SIMULATIONCHAINEDHASHTABLE_H

#include "structures/HashTable/ChainedHashTable.h"

#include <QWidget>

namespace Ui {
class SimulationChainedHashTable;
}

class Controller;

class SimulationChainedHashTable : public QWidget
{
    Q_OBJECT

public:

    const int HASHTABLE_SIZE = 20;
    explicit SimulationChainedHashTable(QWidget *parent = nullptr);
    ~SimulationChainedHashTable();

private:
    Ui::SimulationChainedHashTable *ui;
    ChainedHashTable<int, QString> hashTable;

public:
    friend Controller;
};

#endif // SIMULATIONCHAINEDHASHTABLE_H
