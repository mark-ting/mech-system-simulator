#include "weaponevent.h"
#include "simulationconfig.h"

WeaponEvent::WeaponEvent(Weapon weapon) : SimulationEvent(weapon.getDuration())
{
	int total_ticks = SimulationConfig::secondsToTicks(weapon.getDuration());
	ticks_remaining_ = total_ticks;
	damage_per_tick_ = weapon.getDamage() / total_ticks;
	heat_per_tick_ = weapon.getHeat() / total_ticks;
}

void WeaponEvent::run(Simulation* s)
{
	s->addDamage(damage_per_tick_);
	s->addHeat(heat_per_tick_);
	tick();
}