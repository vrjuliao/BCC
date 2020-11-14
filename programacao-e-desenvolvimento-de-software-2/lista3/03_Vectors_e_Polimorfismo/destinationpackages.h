#ifndef LISTA3_EX4_DESTINATIONPACKAGE
#define LISTA3_EX4_DESTINATIONPACKAGE

#include "package.h"
#include <string>
#include <vector>
#include <map>

class DestinationPackages{
private:
    std::map<std::string, std::vector<Package*>> mPackagesMap;
    //double custo_por_destination(std::vector<Package*>);
public:
    DestinationPackages();
    //DestinationPackages(unsigned int, unsigned int, std::string, std::string);
    void add_package(Package*);
    double custo_total();
    double custo_total(std::string);
    ~DestinationPackages();
};

#endif