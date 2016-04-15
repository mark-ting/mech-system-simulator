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

	double getDamage() const;
	double getHeat() const;

	void addHeat(double heat);
	void addDamage(double damage);

	public slots:
	void reset();
	void tick();
	void scheduleEvent(EventPtr event_object);

signals:
	void tickComplete();

private:
	typedef std::vector<EventPtr> SimulationQueue;
	SimulationQueue event_queue_;

	double damage_;
	double heat_;

	void processEvents();
};