#include <string>
#include <iostream>
#include <fstream>

class Equipment {
    private:
    std::string name;
    double size;
    std::string unit;
    int a;
    int b;
    double n;
    double cost;
    bool successCalc = true;

    public:
    Equipment(std::string name, double size, std::string unit);
    std::string getName() const {return name;}
    double getSize() const {return size;}
    double getCost() const {return cost;}
    std::string getUnit() const {return unit;}
    int geta() const {return a;}
    int getb() const {return b;}
    double getn() const {return n;}    

};

std::ostream& operator<<(std::ostream& os, const Equipment& equipment);

