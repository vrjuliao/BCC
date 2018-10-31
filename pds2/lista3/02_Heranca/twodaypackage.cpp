#include <string>
#include "twodaypackage.h"

TwoDayPackage::TwoDayPackage(unsigned int peso, unsigned int precoPorKg, unsigned int taxaFixa, std::string nome, std::string endereco):
Package(peso, precoPorKg, nome, endereco),mTaxaFixa(taxaFixa)
{}

double TwoDayPackage::calculate_cost(){
    double custo = Package::calculate_cost();
    custo += mTaxaFixa;
    return custo;
}

TwoDayPackage::~TwoDayPackage(){}