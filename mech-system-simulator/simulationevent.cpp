#include "simulationevent.h"

SimulationEvent::SimulationEvent(double time)
{
	ticks_remaining_ = time / GlobalConfig::SIMULATION_TICK_TIME;
}

SimulationEvent::~SimulationEvent()
{
}

std::string SimulationEvent::getName() const
{
	return event_name_;
}

bool SimulationEvent::isComplete()
{
	return !(ticks_remaining_ > 0);
}

void SimulationEvent::tick()
{
	ticks_remaining_--;
}