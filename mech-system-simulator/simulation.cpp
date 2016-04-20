#include "simulation.h"

Simulation::Simulation()
{
	reset();
}

Simulation::~Simulation()
{
}

void Simulation::setMech(Mech* mech)
{
	m_ = mech;
}

void Simulation::addWeapon(std::shared_ptr<Weapon> weapon)
{
	loadout_.push_back(weapon);
}

void Simulation::initialize()
{
	heat_capacity_ = m_->getHeatCapacity();
	heat_dissipation_ = m_->getHeatDissipation();
	heat_dissipation_per_tick_ = heat_dissipation_ / SimulationConfig::SIMULATION_TICK_RATE;
}

void Simulation::pause()
{
	paused_ = !paused_;
}

bool Simulation::isStarted() const
{
	return started_;
}

bool Simulation::isPaused() const
{
	return paused_;
}

double Simulation::getDamage() const
{
	return damage_;
}

double Simulation::getHeat() const
{
	return heat_;
}

double Simulation::getHeatPercent() const
{
	return 100 * heat_ / heat_capacity_;
}

double Simulation::getHeatCapacity() const
{
	return heat_capacity_;
}

double Simulation::getHeatDissipation() const
{
	return heat_dissipation_;
}

void Simulation::addDamage(double damage)
{
	damage_ += damage;
}

void Simulation::addHeat(double heat)
{
	heat_ += heat;
}

void Simulation::start()
{
	started_ = true;
}

void Simulation::stop()
{
	started_ = false;
}

void Simulation::reset()
{
	started_ = false;
	paused_ = false;

	event_queue_.clear();
	resetWeapons();
	m_ = NULL;

	damage_ = 0.0;
	heat_ = 0.0;
	heat_capacity_ = 30.0;
	emit tickComplete();
}

void Simulation::tick()
{
	processEvents();

	if (heat_ + heat_dissipation_per_tick_ > 0) {
		heat_ += heat_dissipation_per_tick_;
	}
	else {
		heat_ = 0.0;
	}
	emit tickComplete();
}

void Simulation::fireWeapon(int weapon_index)
{
	if (weapon_index < loadout_.size()) {
		loadout_[weapon_index]->fire(this);
	}
}

void Simulation::scheduleEvent(EventPtr event_object)
{
	event_queue_.push_back(event_object);
}

void Simulation::processEvents()
{
	for (int i = 0; i < event_queue_.size(); i++) {
		if (event_queue_[i]->isComplete()) {
			event_queue_.erase(event_queue_.begin() + i);
		}
		else {
			event_queue_[i]->run(this);
		}
	}
}

void Simulation::resetWeapons()
{
	for (int i = 0; i < loadout_.size(); i++) {
		loadout_[i]->reload();
	}
}