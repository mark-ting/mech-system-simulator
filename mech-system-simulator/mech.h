#pragma once

class Mech
{
	enum Tech {
		Clan,
		InnerSphere
	};

public:
	Mech();
	~Mech();

	double getHeatCapacity() const;
	double getHeatDissipation() const;

	void setInternalHeatSinks(int heat_sinks);
	void setExternalHeatSinks(int heat_sinks);

	void setDoubleHeatSinks(bool use_double);
	void setCoolRun(bool unlocked);
	void setHeatContainment(bool unlocked);
	void setElited(bool elited);

protected:
	// TODO: make this selectable; default to IS for now.
	Tech tech;

	int internal_heat_sinks_;
	int external_heat_sinks_;

	bool double_heat_sinks_;
	bool cool_run_;
	bool heat_containment_;
	bool elited_;

	double baseHeatCapacity() const;
	double baseHeatDissipation() const;
};