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

private: //methods
    void initTable();
    void curInsertedElement(HashTableElement<int, QString>* element);
    void updateCurInsertedLabel(HashTableElement<int, QString>* element);
    QString elementToString(HashTableElement<int, QString>* element);
    void increaseTableColumns();
    void shiftList(int row);

public:
    friend Controller;
};

#endif // SIMULATIONCHAINEDHASHTABLE_H
