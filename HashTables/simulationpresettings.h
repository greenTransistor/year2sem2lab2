#ifndef SIMULATIONPRESETTINGS_H
#define SIMULATIONPRESETTINGS_H

#include <QWidget>

namespace Ui {
class SimulationPresettings;
}

class SimulationPresettings : public QWidget
{
    Q_OBJECT

public:
    explicit SimulationPresettings(QWidget *parent = nullptr);
    ~SimulationPresettings();

private:
    Ui::SimulationPresettings *ui;
};

#endif // SIMULATIONPRESETTINGS_H
