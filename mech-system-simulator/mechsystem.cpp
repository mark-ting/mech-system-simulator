#include "mechsystem.h"
#include <QDateTime>
#include <QFileDialog>
#include "simulation.h"
#include "simulationconfig.h"
#include "weapon.h"
#include "weaponevent.h"
#include "dataparser.h"

MechSystem::MechSystem(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	m = new Mech();
	s = new Simulation();

	// DEV: Add Large Laser as Test Weapon
	//s->addWeapon(armory[0]);
	// END DEV

	// TEST
	// Debugging CSV loading
	loadWeaponsFromCsv();

	// END TEST

	// DEV
	// Add IS AC20 as Test Weapon
	s->addWeapon(csv_armory[0]);
	// Add IS ERPPC as Test Weapon
	s->addWeapon(weapon_catalog["ERPPC"]);
	// Should result in a total of 30 damage.
	
	// END DEV

	timer = new QTimer(this);
	timer->setTimerType(Qt::PreciseTimer);

	connect(timer, &QTimer::timeout, s, &Simulation::tick);
	connect(s, &Simulation::tickComplete, this, &MechSystem::updateUi);
}

MechSystem::~MechSystem()
{
	delete s;
	delete timer;
}

void MechSystem::startSimulation()
{
	if (s->isPaused()) {
		// Resume if paused
		s->pause();
	}
	else if (!s->isStarted())
	{
		// Start if not yet started
		s->start();
		configureMech();
		ui.heatBar->setMaximum(m->getHeatCapacity());
		s->setMech(m);
		s->initialize();

		// TODO: List weapons in ui.weaponList here.
	}

	timer->start(SimulationConfig::SIMULATION_TICK_TIME);
	ui.statusBar->showMessage("Running");
}

void MechSystem::pauseSimulation()
{
	timer->stop();
	s->pause();
	ui.statusBar->showMessage("Paused");
}

void MechSystem::stopSimulation()
{
	timer->stop();
	s->reset();
	ui.statusBar->showMessage("Stopped");
}

void MechSystem::configureMech()
{
	m->setInternalHeatSinks(ui.intHeatSinkInput->value());
	m->setExternalHeatSinks(ui.extHeatSinkInput->value());
	m->setDoubleHeatSinks(ui.doubleHeatsinkCheck->isChecked());
}

void MechSystem::fireAlpha()
{
	s->fireAlpha();
}

void MechSystem::updateUi()
{
	// TODO: Remove the time display or use it somewhere else
	ui.timeDisplay->setText(QTime::currentTime().toString());
	ui.damageDisplay->setText(QString::number(s->getDamage(), 'f', 2));
	if (s->getHeatPercent() >= 100) {
		ui.heatDisplay->setText("<font color='red'>" + QString::number(s->getHeat(), 'f', 2) + "</font>");
		ui.heatPercentDisplay->setText("<font color='red'>" + QString::number(s->getHeatPercent(), 'f', 2) + "</font>");
	}
	else {
		ui.heatDisplay->setText(QString::number(s->getHeat(), 'f', 2));
		ui.heatPercentDisplay->setText(QString::number(s->getHeatPercent(), 'f', 1));
	}
	ui.heatBar->setValue((int)s->getHeat());
}