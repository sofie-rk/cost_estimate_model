#include "cost_analysis.h"
#include <fstream>
#include <sstream>
#include <math.h>


Equipment::Equipment(std::string name, double size, std::string unit) : name{name}, size{size}, unit{unit}, a{10}, b{10}, n{2}
{
    std::ifstream costData{"cost_table.txt"};

    if (!costData){std::cout<<"Could not open cost table file.\n";}

    std::string line;
    std::string readName;
    std::string readUnit;
    double sLower;
    double sUpper;
    int reada;
    int readb;
    double readn;

    while (getline(costData, line)) {
        std::stringstream ss{line};
        ss >> readName >> unit >> sLower >> sUpper >> reada >> readb >> readn;

        if (!ss) {successCalc = false;}

        if (readName == name) {

            if (size>=sLower && size<=sUpper) {
                a = reada;
                b = readb;
                n = readn;
            }

            else {
                a = 0;
                b = 0;
                n = 0;
                cost = 0;
                successCalc = false;
            }
            break;
        }
    }

    if (successCalc) {
        
        cost = a + b*pow(size, n);

    }

    addEquipmentResult();

}


void Equipment::addEquipmentResult() {

    std::ofstream resultData;

    resultData.open("results.txt", std::ios_base::app);

    if (!resultData){
		std::cout << "Can't open file: results.txt \n"; 
	}

    resultData << name << " " << size << " " << unit << " " << cost << " dollars.\n";
}

std::ostream& operator<<(std::ostream& os, const Equipment& eq) {
    os << "Estimating cost for " << eq.getName() << " with size " << eq.getSize() << eq.getUnit() << std::endl;

    if (eq.getCost() == 0) {
        os << "Size parameter is not within limit.\n";
    }
    else {
        os << "Parameters found in the table: a: " << eq.geta() << " b: " << eq.getb() << " n: " << eq.getn() << std::endl;
        os << "Equipment Cost: " << eq.getCost() << " $" << std::endl;

    }
    

    return os;
}