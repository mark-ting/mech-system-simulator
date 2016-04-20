#pragma once
#include "simulationevent.h"
#include "weapon.h"

class Simulation;
class WeaponEvent : public SimulationEvent
{
public:
	WeaponEvent(Weapon* weapon);
	~WeaponEvent();

	void run(Simulation* s);

protected:
	Weapon* origin_weapon_;
	double heat_per_tick_;
	double damage_per_tick_;
};