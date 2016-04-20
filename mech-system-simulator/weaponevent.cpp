#include "weaponevent.h"
#include "simulationconfig.h"
#include "simulation.h"

WeaponEvent::WeaponEvent(Weapon* weapon)
{
	event_name_ = "Laser Burn";
	int total_ticks = SimulationConfig::secondsToTicks(weapon->getDuration());
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