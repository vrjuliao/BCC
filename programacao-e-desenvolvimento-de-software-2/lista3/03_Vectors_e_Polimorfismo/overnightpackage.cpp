#include <string>
#include "overnightpackage.h"

OverNightPackage::OverNightPackage(unsigned int peso, unsigned int precoPorKg, unsigned int taxaPorKg, std::string nome, std::string endereco):
Package(peso, precoPorKg, nome, endereco), mTaxaPorKg(taxaPorKg)
{}

double OverNightPackage::calculate_cost(){
    double custo;
    unsigned int taxaPadrao = Package::get_custo_por_quilo();
    unsigned int peso = Package::get_peso();
    custo = static_cast<double> (peso * (taxaPadrao + mTaxaPorKg));
    return custo;
}

OverNightPackage::~OverNightPackage(){}