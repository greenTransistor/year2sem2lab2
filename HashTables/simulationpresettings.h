#ifndef SIMULATIONPRESETTINGS_H
#define SIMULATIONPRESETTINGS_H

#include "structures/HashTable/HashTableElement.h"

#include <QWidget>

namespace Ui {
class SimulationPresettings;
}

class Controller;

class SimulationPresettings : public QWidget
{
    Q_OBJECT

public:
    explicit SimulationPresettings(QWidget *parent = nullptr);
    ~SimulationPresettings();

private slots:
    void slotAddElement();

private:
    Ui::SimulationPresettings *ui;
    static QStringList possibleData;

private: //methods
    HashTableElement<int, QString>* getHashTableElement();
    void addElementToTable(HashTableElement<int, QString>* element);
    void clearInputFields();

public:
    friend Controller;
};

#endif // SIMULATIONPRESETTINGS_H
