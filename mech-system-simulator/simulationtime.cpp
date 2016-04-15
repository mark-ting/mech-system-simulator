#include "simulationtime.h"

int SimulationTime::secondsToTicks(double time)
{
	return 1000 * time / GlobalConfig::SIMULATION_TICK_TIME;
}