#pragma once
#include "simulationevent.h"
#include "simulation.h"
#include "weapon.h"

class WeaponEvent : public SimulationEvent
{
public:
	WeaponEvent(Weapon weapon);
	void run(Simulation* s);

protected:
	double heat_per_tick_;
	double damage_per_tick_;
};