#pragma once

// TODO: parse these values from game data instead of hard-coding here.
namespace MechConfig
{
	// Heat Sink Capacity and Dissipation Values
	// Capacity in units of heat
	// Dissipation in units of heat / sec

	// IS Single Heat Sink Values
	const double IS_SHS_INTERNAL_CAPACITY = 1.2;
	const double IS_SHS_EXTERNAL_CAPACITY = 1.2;
	const double IS_SHS_INTERNAL_DISSIPATION = -0.11;
	const double IS_SHS_EXTERNAL_DISSIPATION = -0.12;

	// IS Double Heat Sink Values
	const double IS_DHS_INTERNAL_CAPACITY = 2.0;
	const double IS_DHS_EXTERNAL_CAPACITY = 1.5;
	const double IS_DHS_INTERNAL_DISSIPATION = -0.2;
	const double IS_DHS_EXTERNAL_DISSIPATION = -0.14;

	// Clan Single Heat Sink Values
	const double CLAN_SHS_INTERNAL_CAPACITY = 2;
	const double CLAN_SHS_EXTERNAL_CAPACITY = 1.2;
	const double CLAN_SHS_INTERNAL_DISSIPATION = -0.11;
	const double CLAN_SHS_EXTERNAL_DISSIPATION = -0.12;

	// Clan Double Heat Sink Values
	const double CLAN_DHS_INTERNAL_CAPACITY = 2;
	const double CLAN_DHS_EXTERNAL_CAPACITY = 1.1;
	const double CLAN_DHS_INTERNAL_DISSIPATION = -0.2;
	const double CLAN_DHS_EXTERNAL_DISSIPATION = -0.15;


	// Value of (non-elite) skill in %
	// Cool Run affects dissipation
	// Heat Containment affects capacity

	const double COOL_RUN = 0.075;
	const double HEAT_CONTAINMENT = 0.10;
}