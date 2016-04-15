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

	void setMech(Mech* m);

	double getDamage() const;
	double getHeat() const;

	void addHeat(double heat);
	void addDamage(double damage);

	public slots:
	void reset();
	void tick();
	void stop();
	void scheduleEvent(EventPtr event_object);

signals:
	void tickComplete();

private:
	bool in_progress_;

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