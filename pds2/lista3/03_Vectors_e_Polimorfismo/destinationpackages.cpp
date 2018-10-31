#include "destinationpackages.h"
#include "package.h"
#include <iostream>

/*DestinationPackages::DestinationPackages(unsigned int peso, unsigned int custo_por_quilo, std::string nome, std::string endereco):
Package(peso, custo_por_quilo, nome, endereco)
{}*/

DestinationPackages::DestinationPackages(){}

void DestinationPackages::add_package(Package *package) {
    std::string packacgeName = package->getNome();
    if(mPackagesMap.count(packacgeName) > 0){
       mPackagesMap[packacgeName].push_back(package);
    } else {
        std::vector<Package*> vetor;
        vetor.push_back(package);
        mPackagesMap[packacgeName] = vetor;
    }
}

// double custo_por_destination(std::vector<Package*> destinationPackage){
//     std::cout << "qualquer coisa " << std::endl;
//     double cost = 0.0;
//     for (std::vector<Package*>::iterator it = destinationPackage.begin() ; it != destinationPackage.end(); ++it)
//         cost+= (*it)->calculate_cost();
    
//     return cost;
// }

double DestinationPackages::custo_total(){
    
    if(mPackagesMap.size() > 0){
        double sum = 0.0;
        std::vector<Package*> packs;
        for (std::map<std::string, std::vector<Package*>>::iterator it=mPackagesMap.begin(); it!=mPackagesMap.end(); ++it){
            packs = it->second;
            
            for (std::vector<Package*>::iterator it = packs.begin() ; it != packs.end(); ++it)
                sum+= (*it)->calculate_cost();
            //sum += custo_por_destination(packs);
        }
        return sum;
    } else {
        return 0.0;
    }
}


double DestinationPackages::custo_total(std::string packageName){
    
    if(mPackagesMap.count(packageName) > 0){
        double cost = 0.0;
        std::vector<Package*> packs = mPackagesMap[packageName];
        for (std::vector<Package*>::iterator it = packs.begin() ; it != packs.end(); ++it)
            cost+= (*it)->calculate_cost();
    
        return cost;
        //return custo_por_destination(mPackagesMap[packageName]);
    }
    else {
        return 0.0;
    }
}

DestinationPackages::~DestinationPackages(){}

