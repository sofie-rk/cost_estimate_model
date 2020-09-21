
#include "cost_analysis.h"
#include <fstream>
#include <sstream>

int main()
{
	std::ifstream equipmentData{"equipment.txt"};

	std::string line;
	std::string name;
	std:: string unit;
	double size;

	std::cout << "------------------------------------------------------------------------\n";

	while(getline(equipmentData, line)) {
		std::stringstream ss{line};
        ss >> name >> size >> unit;

		Equipment equipment{name, size, unit};

		std::cout << equipment;

		std::cout << "------------------------------------------------------------------------\n";

	}

}


