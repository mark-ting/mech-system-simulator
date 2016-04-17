#include "simulationconfig.h"

namespace SimulationConfig
{
	// Tick rate in Hz
	const int SIMULATION_TICK_RATE = 100;

	// Tick time in ms
	const int SIMULATION_TICK_TIME = 1000 / SIMULATION_TICK_RATE;

	// Convert seconds to ticks (precision at most to 3 decimal places)
	int secondsToTicks(double time)
	{
		return 1000 * time / SimulationConfig::SIMULATION_TICK_TIME;
	}
}