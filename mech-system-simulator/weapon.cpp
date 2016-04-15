#include "weapon.h"

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