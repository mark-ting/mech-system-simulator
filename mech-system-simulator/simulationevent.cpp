#include "simulationevent.h"

SimulationEvent::SimulationEvent()
{
}

SimulationEvent::~SimulationEvent()
{
}

std::string SimulationEvent::getName() const
{
	return event_name_;
}

bool SimulationEvent::isComplete() const
{
	return !(ticks_remaining_ > 0);
}

void SimulationEvent::tick()
{
	ticks_remaining_--;
}