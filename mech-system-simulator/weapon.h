#pragma once
#include <memory>
#include <vector>
#include "simulation.h"

class Weapon
{
public:
	Weapon(double damage, double heat, double cooldown, double duration) :
		damage_(damage), heat_(heat), cooldown_(cooldown), duration_(duration) {};
	~Weapon();

	double getDamage() const;
	double getHeat() const;
	double getCooldown() const;
	double getDuration() const;

	void fireWeapon(Simulation* s);

protected:
	double damage_;
	double heat_;
	double cooldown_;
	double duration_;
};

typedef std::shared_ptr<Weapon> WeaponPtr;
typedef std::vector<WeaponPtr> WeaponLoadout;