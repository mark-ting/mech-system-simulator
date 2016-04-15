#include "mechsystem.h"
#include <QDateTime>
#include "simulation.h"
#include "GlobalConfig.h"

#include "weapon.h"
#include "weaponevent.h"

MechSystem::MechSystem(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	m = new Mech();
	s = new Simulation();
	timer = new QTimer(this);
	timer->setTimerType(Qt::PreciseTimer);

	connect(timer, &QTimer::timeout, s, &Simulation::tick);
	connect(s, &Simulation::tickComplete, this, &MechSystem::updateUi);

	// TODO: move this to manual function
	configureMech();
	double debug = m->getHeatDissipation();
 	ui.heatBar->setMaximum(m->getHeatCapacity());
	s->setMech(m);
}

MechSystem::~MechSystem()
{
	delete s;
	delete timer;
}

void MechSystem::startSimulation()
{
	timer->start(GlobalConfig::SIMULATION_TICK_TIME);
}

void MechSystem::pauseSimulation()
{
	timer->stop();
}

void MechSystem::resetSimulation()
{
	s->reset();
}

void MechSystem::configureMech()
{
	m->setEngine(ui.engineSelect->value());
	m->setHeatSinks(ui.extHeatSinkInput->value());
	m->useDoubleHeatSinks(ui.doubleHeatsinkCheck->isChecked());
}

void MechSystem::fireAlpha()
{
	Weapon w = Weapon(9, 7, 3.25, 1.0);
	std::shared_ptr<WeaponEvent> we = (std::shared_ptr<WeaponEvent>) new WeaponEvent(w);
	s->scheduleEvent(we);
}

void MechSystem::updateUi()
{
	// TODO: Remove the time display or use it somewhere else
	ui.timeDisplay->setText(QTime::currentTime().toString());
	ui.damageDisplay->setText(QString::number(s->getDamage()));
	ui.heatDisplay->setText(QString::number(s->getHeat()));
	ui.heatBar->setValue((int)s->getHeat());
}