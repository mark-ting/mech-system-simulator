#pragma once

namespace MechConfig
{
	// Heat Sink Capacity and Dissipation Values
	// Capacity in units of heat
	// Dissipation in units of heat / sec

	// IS Single Heat Sink Values
	extern const double IS_SHS_INTERNAL_CAPACITY;
	extern const double IS_SHS_EXTERNAL_CAPACITY;
	extern const double IS_SHS_INTERNAL_DISSIPATION;
	extern const double IS_SHS_EXTERNAL_DISSIPATION;

	// IS Double Heat Sink Values
	extern const double IS_DHS_INTERNAL_CAPACITY;
	extern const double IS_DHS_EXTERNAL_CAPACITY;
	extern const double IS_DHS_INTERNAL_DISSIPATION;
	extern const double IS_DHS_EXTERNAL_DISSIPATION;

	// Clan Single Heat Sink Values
	extern const double CLAN_SHS_INTERNAL_CAPACITY;
	extern const double CLAN_SHS_EXTERNAL_CAPACITY;
	extern const double CLAN_SHS_INTERNAL_DISSIPATION;
	extern const double CLAN_SHS_EXTERNAL_DISSIPATION;

	// Clan Double Heat Sink Values
	extern const double CLAN_DHS_INTERNAL_CAPACITY;
	extern const double CLAN_DHS_EXTERNAL_CAPACITY;
	extern const double CLAN_DHS_INTERNAL_DISSIPATION;
	extern const double CLAN_DHS_EXTERNAL_DISSIPATION;

	// Value of (non-elite) skill in %
	// Cool Run affects dissipation
	// Heat Containment affects capacity
	extern const double COOL_RUN;
	extern const double HEAT_CONTAINMENT;
}