#ifndef SIMULATIONCHAINEDHASHTABLE_H
#define SIMULATIONCHAINEDHASHTABLE_H

#include "structures/HashTable/ChainedHashTable.h"
#include "structures/HashTable/OpenAdressingHashTable.h"
#include "structures/HashTable/probingStrategies/LinearProbingStrategy.h"
#include "structures/HashTable/probingStrategies/SecondHashProbingStrategy.h"

#include <QWidget>

enum Entity {
    Chained,
    OpenAdressingLinear,
    OpenAdressingSecondary
};

namespace Ui {
class SimulationChainedHashTable;
}

class Controller;

class SimulationChainedHashTable : public QWidget
{
    Q_OBJECT

public:

//    const int HASHTABLE_SIZE = 8;
    explicit SimulationChainedHashTable(Entity entity, QWidget *parent = nullptr);
    ~SimulationChainedHashTable();

private:
    Ui::SimulationChainedHashTable *ui;
    MutableHashTable<int, QString>* hashTable;
    int tableSize;
    Entity entity;

public slots:
    void slotOnNextFindButton();

private: //methods
    void initTable();
    void findElement();
    void curInsertedElement(HashTableElement<int, QString>* element);
    void updateCurInsertedLabel(HashTableElement<int, QString>* element);
    QString elementToString(HashTableElement<int, QString>* element);
    void increaseTableColumns();
    void shiftList(int row);

public:
    friend Controller;
};

#endif // SIMULATIONCHAINEDHASHTABLE_H
