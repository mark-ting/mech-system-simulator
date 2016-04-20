#pragma once
#include "simulationconfig.h"
#include <string>
#include <memory>
#include <vector>

class Simulation;
class SimulationEvent
{
public:
	SimulationEvent();
	~SimulationEvent();

	std::string getName() const;
	virtual bool isComplete() const;
	virtual void run(Simulation* s) = 0;

protected:
	std::string event_name_;
	int ticks_remaining_;

	void tick();
};

typedef std::shared_ptr<SimulationEvent> EventPtr;
typedef std::vector<EventPtr> EventQueue;