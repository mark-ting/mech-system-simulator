#include "weapon.h"
#include "weaponevent.h"

Weapon::~Weapon()
{
}

double Weapon::getDamage() const
{
	return damage_;
}

double Weapon::getHeat() const
{
	return heat_;
}

double Weapon::getCooldown() const
{
	return cooldown_;
}

double Weapon::getDuration() const
{
	return duration_;
}

void Weapon::fireWeapon(Simulation * s)
{
	std::shared_ptr<WeaponEvent> we = (std::shared_ptr<WeaponEvent>) new WeaponEvent(*this);
	s->scheduleEvent(we);
}
