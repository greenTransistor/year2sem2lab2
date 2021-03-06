#include "simulationpresettings.h"
#include "ui_simulationpresettings.h"

QStringList SimulationPresettings::possibleData = {
    "apple",
    "word",
    "time",
    "laptop",
    "builder",
    "factory",
    "data",
    "random",
    "problem",
    "note",
    "text",
    "some",
    "gold"
};

SimulationPresettings::SimulationPresettings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SimulationPresettings)
{
    ui->setupUi(this);

    connect(ui->addButton, SIGNAL(clicked()), this, SLOT(slotAddElement()));
}

SimulationPresettings::~SimulationPresettings()
{
    delete ui;
}

void SimulationPresettings::slotAddElement()
{
    HashTableElement<int, QString>* element = getHashTableElement();
    addElementToTable(element);
}

HashTableElement<int, QString> *SimulationPresettings::getHashTableElement()
{
    int key;
    QString* data;
    if (ui->needRandomRadioButton->isChecked()){
        key = rand() % 100;
        data = new QString(possibleData[rand() % possibleData.size()]);
    }
    else{
        key = ui->keyInput->text().toInt();
        data = new QString(ui->dataInput->text());
    }

    return new HashTableElement<int, QString>(key, data);
}

void SimulationPresettings::addElementToTable(HashTableElement<int, QString> *element)
{
    int curRowsNumber = ui->elementsTable->rowCount();
    ui->elementsTable->setRowCount(curRowsNumber+1);

    ui->elementsTable->setItem(curRowsNumber, 0, new QTableWidgetItem(QString::number(element->key)));
    ui->elementsTable->setItem(curRowsNumber, 1, new QTableWidgetItem(*(element->data)));
}

void SimulationPresettings::clearInputFields()
{
    ui->keyInput->setText("");
    ui->dataInput->setText("");
}
