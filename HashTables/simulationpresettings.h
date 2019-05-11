#ifndef SIMULATIONPRESETTINGS_H
#define SIMULATIONPRESETTINGS_H

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

private:
    Ui::SimulationPresettings *ui;

public:
    friend Controller;
};

#endif // SIMULATIONPRESETTINGS_H
