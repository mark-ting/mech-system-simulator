#include "mech.h"
#include "mechconfig.h"

double Mech::getHeatCapacity() const
{
	if (tech == Clan) {
		if (double_heat_sinks_) {
			return (calcInternalHeatSinks() * MechConfig::CLAN_DHS_INTERNAL_CAPACITY +
				external_heat_sinks_ * MechConfig::CLAN_DHS_EXTERNAL_CAPACITY);
		}
		else {
			return (calcInternalHeatSinks() * MechConfig::CLAN_SHS_INTERNAL_CAPACITY +
				external_heat_sinks_ * MechConfig::CLAN_SHS_EXTERNAL_CAPACITY);
		}
	}
	else {
		if (double_heat_sinks_) {
			return (calcInternalHeatSinks() * MechConfig::IS_DHS_INTERNAL_CAPACITY +
				external_heat_sinks_ * MechConfig::IS_DHS_EXTERNAL_CAPACITY);
		}
		else {
			return (calcInternalHeatSinks() * MechConfig::IS_SHS_INTERNAL_CAPACITY +
				external_heat_sinks_ * MechConfig::IS_SHS_EXTERNAL_CAPACITY);
		}
	}
}

double Mech::getHeatDissipation() const
{
	if (tech == Clan) {
		if (double_heat_sinks_) {
			return (calcInternalHeatSinks() * MechConfig::CLAN_DHS_INTERNAL_DISSIPATION +
				external_heat_sinks_ * MechConfig::CLAN_DHS_EXTERNAL_DISSIPATION);
		}
		else {
			return (calcInternalHeatSinks() * MechConfig::CLAN_SHS_INTERNAL_DISSIPATION +
				external_heat_sinks_ * MechConfig::CLAN_SHS_EXTERNAL_DISSIPATION);
		}
	}
	else {
		if (double_heat_sinks_) {
			return (calcInternalHeatSinks() * MechConfig::IS_DHS_INTERNAL_DISSIPATION +
				external_heat_sinks_ * MechConfig::IS_DHS_EXTERNAL_DISSIPATION);
		}
		else {
			return (calcInternalHeatSinks() * MechConfig::IS_SHS_INTERNAL_DISSIPATION +
				external_heat_sinks_ * MechConfig::IS_SHS_EXTERNAL_DISSIPATION);
		}
	}
}

void Mech::setEngine(int engine)
{
	engine_size_ = engine;
}

void Mech::setHeatSinks(int heat_sinks)
{
	external_heat_sinks_ = heat_sinks;
}

void Mech::setSkills(bool cool, bool heat, bool elite)
{
	cool_run_ = cool;
	heat_containment_ = heat;
	elited_ = elite;
}

void Mech::useDoubleHeatSinks(bool use_double)
{
	double_heat_sinks_ = use_double;
}

int Mech::calcInternalHeatSinks() const
{
	return (engine_size_ > 250) ? 10 : (engine_size_ / 25);
}
