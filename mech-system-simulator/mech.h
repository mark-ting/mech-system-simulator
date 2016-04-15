#pragma once

class Mech
{
	enum Tech {
		Clan,
		InnerSphere
	};

public:
	double getHeatCapacity() const;
	double getHeatDissipation() const;

	void setEngine(int engine);
	void setHeatSinks(int heat_sinks);
	void setSkills(bool cool, bool heat, bool elite);
	void useDoubleHeatSinks(bool use_double);

protected:
	// TODO: make this selectable; default to IS for now.
	Tech tech = InnerSphere;

	int engine_size_;
	int internal_heat_sinks_;
	int external_heat_sinks_;

	bool double_heat_sinks_;
	bool cool_run_;
	bool heat_containment_;
	bool elited_;

	int calcInternalHeatSinks() const;
};