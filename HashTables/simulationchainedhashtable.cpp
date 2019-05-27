#include "simulationchainedhashtable.h"
#include "ui_simulationchainedhashtable.h"

#include <QDebug>

SimulationChainedHashTable::SimulationChainedHashTable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SimulationChainedHashTable),
    hashTable(ChainedHashTable<int, QString>(HASHTABLE_SIZE))
{
    ui->setupUi(this);
    initTable();
}

SimulationChainedHashTable::~SimulationChainedHashTable()
{
    delete ui;
}

void SimulationChainedHashTable::initTable()
{
    ui->tableWidget->setRowCount(HASHTABLE_SIZE);
    ui->tableWidget->setColumnCount(1);
    for (int i = 0; i < HASHTABLE_SIZE; i++)
        ui->tableWidget->setItem(i,0, new QTableWidgetItem(QString("---> \\")));
}

void SimulationChainedHashTable::curInsertedElement(HashTableElement<int, QString> *element)
{
    updateCurInsertedLabel(element);

    hashTable.insert(*element);

    std::pair<int, int>* position = hashTable.popActiveElement();
    int row = position->first;
    increaseTableColumns();
    shiftList(row);

    QTableWidgetItem* item = new QTableWidgetItem(QString("---> ") + elementToString(element));
    ui->tableWidget->setItem(row, 0, item);
    ui->tableWidget->setCurrentItem(item);
}

void SimulationChainedHashTable::updateCurInsertedLabel(HashTableElement<int, QString> *element)
{
    ui->curInsertElement->setText(elementToString(element));
}

QString SimulationChainedHashTable::elementToString(HashTableElement<int, QString> *element)
{
    return QString::number(element->key) + "| " + *element->data;
}

void SimulationChainedHashTable::increaseTableColumns()
{
    int curColumnsNumber = ui->tableWidget->columnCount();
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
