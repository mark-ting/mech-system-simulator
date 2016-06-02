#pragma once
#include "weapon.h"
#include "mech.h"
#include <vector>
#include <string>

void loadWeaponsFromCsv();
int countCsvFields(std::ifstream& file);

// Push CSV fields into a vector and continue to the next line
std::vector<std::string> getCsvFields(std::ifstream& file);

extern WeaponLoadout csv_armory;
extern WeaponCatalog weapon_catalog;