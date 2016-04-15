#include "simulation.h"

Simulation::Simulation()
{
	reset();
}

Simulation::~Simulation()
{
}

double Simulation::getDamage() const
{
	return damage_;
}

double Simulation::getHeat() const
{
	return heat_;
}

void Simulation::addDamage(double damage)
{
	damage_ += damage;
}

void Simulation::addHeat(double heat)
{
	heat_ += heat;
}

void Simulation::reset()
{
	event_queue_.clear();
	heat_ = 0.0;
	damage_ = 0.0;
	emit tickComplete();
}

void Simulation::tick()
{
	processEvents();
	emit tickComplete();
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