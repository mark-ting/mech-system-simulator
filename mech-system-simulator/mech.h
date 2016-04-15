#pragma once

class Mech
{
public:
	int getInternalHeatSinks() const;
	int getExternalHeatSinks() const;

	void setEngine(int engine);
	void setHeatSinks(int heat_sinks);

protected:
	int engine_size_;
	int internal_heat_sinks_;
	int external_heat_sinks_;

	void calcInternalHeatSinks() { internal_heat_sinks_ = (engine_size_ > 250) ? 10 : (engine_size_ / 25); };
};