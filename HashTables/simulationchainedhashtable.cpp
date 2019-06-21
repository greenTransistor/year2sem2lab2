#include "simulationchainedhashtable.h"
#include "ui_simulationchainedhashtable.h"

#include <QDebug>

SimulationChainedHashTable::SimulationChainedHashTable(Entity entity, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SimulationChainedHashTable),
    entity(entity)
{
    if (entity == Chained) tableSize = 8;
    else tableSize = 20;

    if (entity == Chained) hashTable = new ChainedHashTable<int, QString>(tableSize);
    else if (entity == OpenAdressingLinear) hashTable = new OpenAdressingHashTable<int, QString>(new LinearProbingStrategy(), tableSize);
    else if (entity == OpenAdressingSecondary) hashTable = new OpenAdressingHashTable<int, QString>(new SecondHashProbingStrategy(tableSize), tableSize);

    ui->setupUi(this);
    initTable();
}

SimulationChainedHashTable::~SimulationChainedHashTable()
{
    delete ui;
}

void SimulationChainedHashTable::findElement()
{
    int key = ui->keyToFindInput->text().toInt();
    hashTable->find(key);
}

void SimulationChainedHashTable::slotOnNextFindButton()
{
    if (ui->keyToFindInput->text() != ""){
        findElement();
        ui->keyToFindInput->setText("");
    }
    if (!hashTable->activeElementsElementsAvailable()) return;
    std::pair<int, int>* position = hashTable->popActiveElement();
    ui->tableWidget->setCurrentCell(position->first, position->second);
}

void SimulationChainedHashTable::initTable()
{
    ui->tableWidget->setRowCount(tableSize);
    ui->tableWidget->setColumnCount(1);
    for (int i = 0; i < tableSize; i++)
        ui->tableWidget->setItem(i,0, new QTableWidgetItem(QString("--> \\")));
}

void SimulationChainedHashTable::curInsertedElement(HashTableElement<int, QString> *element)
{
    updateCurInsertedLabel(element);

    hashTable->insert(*element);

    std::pair<int, int>* position = hashTable->popActiveElement();
    int row = position->first;
    increaseTableColumns();
    shiftList(row);

    QTableWidgetItem* item = new QTableWidgetItem(QString("--> ") + elementToString(element));
    ui->tableWidget->setItem(row, 0, item);
    ui->tableWidget->setCurrentItem(item);
}

void SimulationChainedHashTable::updateCurInsertedLabel(HashTableElement<int, QString> *element)
{
    ui->curInsertElement->setText(elementToString(element));
}

QString SimulationChainedHashTable::elementToString(HashTableElement<int, QString> *element)
{
    return QString::number(element->key) + " | " + *element->data;
}

void SimulationChainedHashTable::increaseTableColumns()
{
    int curColumnsNumber = ui->tableWidget->columnCount();
    if (entity != Chained && curColumnsNumber == 2) return;

    ui->tableWidget->setColumnCount(curColumnsNumber + 1);
}

void SimulationChainedHashTable::shiftList(int row)
{
    for (int j = ui->tableWidget->columnCount()-1; j >= 1; j--){
        if (ui->tableWidget->item(row, j-1)){
            QTableWidgetItem* item = new QTableWidgetItem(ui->tableWidget->item(row, j-1)->text());
            ui->tableWidget->setItem(row, j, item);
        }
    }
}
