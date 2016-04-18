#include "mech.h"
#include "mechconfig.h"

Mech::Mech()
{
	tech = Tech::InnerSphere;

	internal_heat_sinks_ = 0;
	external_heat_sinks_ = 0;

	double_heat_sinks_ = false;
	cool_run_ = false;
	heat_containment_ = false;
	elited_ = false;
}

Mech::~Mech()
{
}

double Mech::getHeatCapacity() const
{
	double modifier = (1 + elited_) * heat_containment_ * MechConfig::HEAT_CONTAINMENT;
	return baseHeatCapacity() * (1.0 + (1 + elited_) * heat_containment_ * MechConfig::HEAT_CONTAINMENT);
}

double Mech::getHeatDissipation() const
{
	double modifier = (1 + elited_) * cool_run_ * MechConfig::COOL_RUN;
	return baseHeatDissipation() * (1.0 + (1 + elited_) * cool_run_ * MechConfig::COOL_RUN);
}

void Mech::setInternalHeatSinks(int heat_sinks)
{
	internal_heat_sinks_ = heat_sinks;
}

void Mech::setExternalHeatSinks(int heat_sinks)
{
	external_heat_sinks_ = heat_sinks;
}

void Mech::setDoubleHeatSinks(bool use_double)
{
	double_heat_sinks_ = use_double;
}

void Mech::setCoolRun(bool unlocked)
{
	cool_run_ = unlocked;
}

void Mech::setHeatContainment(bool unlocked)
{
	heat_containment_ = unlocked;
}

void Mech::setElited(bool elited)
{
	elited_ = elited;
}

double Mech::baseHeatCapacity() const
{
	if (tech == Clan) {
		if (double_heat_sinks_) {
			return 30.0 + (internal_heat_sinks_ * MechConfig::CLAN_DHS_INTERNAL_CAPACITY +
				external_heat_sinks_ * MechConfig::CLAN_DHS_EXTERNAL_CAPACITY);
		}
		else {
			return 30.0 + (internal_heat_sinks_ * MechConfig::CLAN_SHS_INTERNAL_CAPACITY +
				external_heat_sinks_ * MechConfig::CLAN_SHS_EXTERNAL_CAPACITY);
		}
	}
	else {
		if (double_heat_sinks_) {
			return 30.0 + (internal_heat_sinks_ * MechConfig::IS_DHS_INTERNAL_CAPACITY +
				external_heat_sinks_ * MechConfig::IS_DHS_EXTERNAL_CAPACITY);
		}
		else {
			return 30.0 + (internal_heat_sinks_ * MechConfig::IS_SHS_INTERNAL_CAPACITY +
				external_heat_sinks_ * MechConfig::IS_SHS_EXTERNAL_CAPACITY);
		}
	}
}

double Mech::baseHeatDissipation() const
{
	if (tech == Clan) {
		if (double_heat_sinks_) {
			return (internal_heat_sinks_ * MechConfig::CLAN_DHS_INTERNAL_DISSIPATION +
				external_heat_sinks_ * MechConfig::CLAN_DHS_EXTERNAL_DISSIPATION);
		}
		else {
			return (internal_heat_sinks_ * MechConfig::CLAN_SHS_INTERNAL_DISSIPATION +
				external_heat_sinks_ * MechConfig::CLAN_SHS_EXTERNAL_DISSIPATION);
		}
	}
	else {
		if (double_heat_sinks_) {
			return (internal_heat_sinks_ * MechConfig::IS_DHS_INTERNAL_DISSIPATION +
				external_heat_sinks_ * MechConfig::IS_DHS_EXTERNAL_DISSIPATION);
		}
		else {
			return (internal_heat_sinks_ * MechConfig::IS_SHS_INTERNAL_DISSIPATION +
				external_heat_sinks_ * MechConfig::IS_SHS_EXTERNAL_DISSIPATION);
		}
	}
}