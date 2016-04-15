#ifndef MECHSYSTEM_H
#define MECHSYSTEM_H

#include <QtWidgets/QMainWindow>
#include <QTimer>
#include "ui_mechsystem.h"
#include "simulation.h"

class MechSystem : public QMainWindow
{
	Q_OBJECT

public:
	MechSystem(QWidget *parent = 0);
	~MechSystem();

	private slots:
	void startSimulation();
	void pauseSimulation();
	void resetSimulation();
	void updateUi();
	void fireAlpha();

private:
	Ui::MechSystemClass ui;
	Simulation* s;
	QTimer* timer;
};

#endif // MECHSYSTEM_H
