#pragma once
#include "simulationevent.h"
#include "weapon.h"

class CoolDownEvent : public SimulationEvent
{
public:
	CoolDownEvent(Weapon* weapon);
	~CoolDownEvent();

	bool isComplete() const;
	void run(Simulation* s);

private:
	Weapon* origin_weapon_;
};