#pragma once
#include "GlobalConfig.h"
#include <string>
#include <memory>

class Simulation;
class SimulationEvent
{
public:
	SimulationEvent(double time);
	~SimulationEvent();

	std::string getName() const;
	bool isComplete();
	virtual void run(Simulation* s) = 0;

protected:
	std::string event_name_;
	int ticks_remaining_;

	void tick();
};

typedef std::shared_ptr<SimulationEvent> EventPtr;