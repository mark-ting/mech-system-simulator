#pragma once
#include <memory>
#include <vector>
#include <unordered_map>
#include <string>

class Simulation;
class Weapon
{
public:
	Weapon(double damage, double heat, double cooldown, double duration) :
		damage_(damage), heat_(heat), cooldown_(cooldown), duration_(duration) {};
	Weapon(std::unordered_map<std::string, std::string>);
	~Weapon();

	std::string getName() const;

	double getDamage() const;
	double getHeat() const;
	double getCoolDown() const;
	double getDuration() const;

	void fire(Simulation* s);
	void reload();

protected:
	int id_;
	std::string name_;
	std::string category_;

	double damage_;
	double cooldown_;
	double heat_;
	double duration_;

	double min_range_;
	double opt_range_;
	double max_range_;

	bool off_cooldown_;
};

typedef std::shared_ptr<Weapon> WeaponPtr;
typedef std::vector<WeaponPtr> WeaponLoadout;
typedef std::unordered_map<std::string, std::string> WeaponDescriptor;

// Load all weapons into memory
// TODO: make this load programmatically, and not just a single IS LL
extern WeaponLoadout armory;

void loadWeapons();