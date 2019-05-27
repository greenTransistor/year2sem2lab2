#ifndef SIMULATIONCHAINEDHASHTABLE_H
#define SIMULATIONCHAINEDHASHTABLE_H

#include <QWidget>

namespace Ui {
class SimulationChainedHashTable;
}

class SimulationChainedHashTable : public QWidget
{
    Q_OBJECT

public:
    explicit SimulationChainedHashTable(QWidget *parent = nullptr);
    ~SimulationChainedHashTable();

private:
    Ui::SimulationChainedHashTable *ui;
};

#endif // SIMULATIONCHAINEDHASHTABLE_H
