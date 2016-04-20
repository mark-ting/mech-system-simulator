#pragma once
#include <QObject>
#include <vector>
#include <memory>
#include "mech.h"
#include "weapon.h"
#include "simulationevent.h"

class Simulation : public QObject
{
	Q_OBJECT

public:
	Simulation();
	~Simulation();

	// Assign Mech to Simulation
	void setMech(Mech* mech);
	void addWeapon(std::shared_ptr<Weapon> weapon);

	// Lock-in values from Mech, Environment, Quirks, etc.
	void initialize();
	void pause();

	bool isStarted() const;
	bool isPaused() const;

	double getDamage() const;
	double getHeat() const;
	double getHeatPercent() const;

	double getHeatCapacity() const;
	double getHeatDissipation() const;

	void addDamage(double damage);
	void addHeat(double heat);

	public slots:
	void start();
	void stop();
	void reset();
	void tick();
	void fireWeapon(int weapon_index);
	void scheduleEvent(EventPtr event_object);

signals:
	void tickComplete();

private:
	bool started_;  // flag to avoid being "started" again (avoid reinit errors)
	bool paused_;

	EventQueue event_queue_;
	WeaponLoadout loadout_;
	Mech* m_;

	double damage_;
	double heat_;
	double heat_capacity_;
	double heat_dissipation_;  // per second value
	double heat_dissipation_per_tick_;

	void processEvents();
	void resetWeapons();
};