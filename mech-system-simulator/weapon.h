#pragma once
#include <memory>
#include <vector>

class Simulation;
class Weapon
{
public:
	Weapon(double damage, double heat, double cooldown, double duration) :
		damage_(damage), heat_(heat), cooldown_(cooldown), duration_(duration) {};
	~Weapon();

	double getDamage() const;
	double getHeat() const;
	double getCoolDown() const;
	double getDuration() const;

	void fire(Simulation* s);
	void reload();

protected:
	double damage_;
	double heat_;
	double cooldown_;
	double duration_;

	bool off_cooldown_;
};

typedef std::shared_ptr<Weapon> WeaponPtr;
typedef std::vector<WeaponPtr> WeaponLoadout;

// Load all weapons into memory
// TODO: make this load programmatically, and not just a single IS LL
extern WeaponLoadout armory;

void loadWeapons();