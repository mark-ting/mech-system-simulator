#include "weaponevent.h"
#include "simulationconfig.h"
#include "simulation.h"

WeaponEvent::WeaponEvent(Weapon* weapon)
{
	event_name_ = weapon->getName() + " Fire";
	int total_ticks;

	if (weapon->getDuration() > 0) {
		// Duration-based weapons spread out value-adds over ticks
		total_ticks = SimulationConfig::secondsToTicks(weapon->getDuration());
	}
	else {
		// Instantaneous weapons apply all values in a single tick
		total_ticks = 1;
	}

	ticks_remaining_ = total_ticks;
	damage_per_tick_ = weapon->getDamage() / total_ticks;
	heat_per_tick_ = weapon->getHeat() / total_ticks;
}

WeaponEvent::~WeaponEvent()
{
}

void WeaponEvent::run(Simulation* s)
{
	s->addDamage(damage_per_tick_);
	s->addHeat(heat_per_tick_);
	tick();
}