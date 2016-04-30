#include "weapon.h"
#include "weaponevent.h"
#include "cooldownevent.h"
#include "simulation.h"

Weapon::Weapon(std::unordered_map<std::string, std::string> details) :
	id_(std::stoi(details["Weapon ID"])),
	name_(details["Name"]),
	category_(details["Category"]),

	damage_(std::stod(details["Damage"])),
	cooldown_(std::stod(details["Cool Down"])),
	heat_(std::stod(details["Heat"])),
	duration_(std::stod(details["Duration"]))
{}

Weapon::~Weapon()
{
}

std::string Weapon::getName() const
{
	return name_;
}

double Weapon::getDamage() const
{
	return damage_;
}

double Weapon::getHeat() const
{
	return heat_;
}

double Weapon::getCoolDown() const
{
	return cooldown_;
}

double Weapon::getDuration() const
{
	return duration_;
}

void Weapon::fire(Simulation * s)
{
	if (off_cooldown_) {
		off_cooldown_ = false;

		// Schedule Weapon Fire Event
		std::shared_ptr<WeaponEvent> we = (std::shared_ptr<WeaponEvent>) new WeaponEvent(this);
		s->scheduleEvent(we);

		// Schedule Weapon Cool Down Event
		std::shared_ptr<CoolDownEvent> ce = (std::shared_ptr<CoolDownEvent>) new CoolDownEvent(this);
		s->scheduleEvent(ce);

		double test = s->getHeat();
	}
}

void Weapon::reload()
{
	off_cooldown_ = true;
}

std::vector<std::shared_ptr<Weapon>> armory;

// Load weapons into memory
void loadWeapons()
{
	// armory.push_back((std::shared_ptr<Weapon>) new Weapon(1, 1, 0.05, 0.05));  // Test Weapon
	armory.push_back((WeaponPtr) new Weapon(9, 7, 3.25, 1.0));  // Large Laser
}