#pragma once
#include <QObject>
#include <Vector>
#include <Memory>
#include "mech.h"
#include "simulationevent.h"

class Simulation : public QObject
{
	Q_OBJECT

public:
	Simulation();
	~Simulation();

	// Assign Mech to Simulation
	void setMech(Mech* mech);

	// Lock-in values from Mech, Environment, Quirks, etc.
	void initialize();
	void pause();

	bool isStarted() const;
	bool isPaused() const;

	double getDamage() const;
	double getHeat() const;
	double getHeatPercent() const;

	void addDamage(double damage);
	void addHeat(double heat);

	public slots:
	void start();
	void stop();
	void reset();
	void tick();
	void scheduleEvent(EventPtr event_object);

signals:
	void tickComplete();

private:
	bool started_;  // prevent simulation from being "started" again (avoid reinitialization errors)
	bool paused_;

	typedef std::vector<EventPtr> SimulationQueue;
	SimulationQueue event_queue_;
	Mech* m;

	double damage_;
	double heat_;
	double heat_capacity_;
	double heat_dissipation_;
	double heat_dissipation_per_tick_;

	void processEvents();
};