#include "dataparser.h"
#include <unordered_map>
#include <fstream>
#include <sstream>

std::vector<std::shared_ptr<Mech>> csv_hangar;
//std::unordered_map<int, std::shared_ptr<Weapon>> csv_armory;
WeaponLoadout csv_armory;
WeaponCatalog weapon_catalog;

void loadWeaponsFromCsv()
{
	std::vector<WeaponDescriptor> descriptor_list;
	std::vector<std::string> fields;
	WeaponDescriptor weapon_descriptor;

	std::ifstream weapon_file("weapons.csv");

	// Get CSV Fields and move to next line
	fields = getCsvFields(weapon_file);
	int columns = fields.size();

	// Process each CSV record (weapon)
	std::string record_line;
	while (std::getline(weapon_file, record_line, '\n'))
	{
		// Clean up
		weapon_descriptor.clear();

		std::istringstream record(record_line);
		std::string field;

		// Process each Field in Record
		for (int i = 0; i < columns; i++) {
			std::getline(record, field, ',');
			weapon_descriptor.insert({ fields[i], field });
		}

		// Insert weapon descriptor into list
		descriptor_list.push_back(weapon_descriptor);
	}

	for (auto const& descriptor : descriptor_list) {
		WeaponPtr weapon = (WeaponPtr) new Weapon(descriptor);
		csv_armory.push_back(weapon);
		weapon_catalog.insert({ weapon->getName(), weapon });
	}
}

int countCsvFields(std::ifstream & file)
{
	file.seekg(0);     // reset to header row
	int elements = 1;  // at least one header item in .csv

	std::string line;
	std::getline(file, line, '\n');

	for (int i = 0; i < line.size(); i++) {
		if (line[i] == ',') {
			elements++;
		}
	}

	file.seekg(0);  // reset once more
	return elements;
}

std::vector<std::string> getCsvFields(std::ifstream & file)
{
	std::vector<std::string> fields;

	// Read header row
	std::string header_row;
	std::getline(file, header_row, '\n');
	std::istringstream header_stream(header_row);

	// Read fields
	std::string field;
	while (std::getline(header_stream, field, ',')) {
		fields.push_back(field);
	}

	return fields;
}