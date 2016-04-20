#include "cooldownevent.h"

CoolDownEvent::CoolDownEvent(Weapon* weapon)
{
	event_name_ = "Cooldown Timer";
	int total_ticks = SimulationConfig::secondsToTicks(weapon->getCoolDown() + weapon->getDuration());
	ticks_remaining_ = total_ticks;
	origin_weapon_ = weapon;
}

CoolDownEvent::~CoolDownEvent()
{
}

bool CoolDownEvent::isComplete() const
{
	if (ticks_remaining_ > 0) {
		return false;
	}
	else {
		origin_weapon_->reload();
		return true;
	}
}

void CoolDownEvent::run(Simulation * s)
{
	tick();
}