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
	s = new Simulation();
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

void MechSystem::fireAlpha()
{
	Weapon w = Weapon(10, 10, 10, 1.0);
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