#include <string>
#include "package.h"

Package::Package(unsigned int peso, unsigned int precoPorKg, std::string nome, std::string endereco):
mEndereco(endereco), mNome(nome), mPeso(peso), mPrecoPorKg(precoPorKg)
{}

double Package::calculate_cost(){
    return static_cast<double> (mPeso * mPrecoPorKg);
}

std::string Package::getNome(){
    return mNome;
}

std::string Package::getEndereco(){
    return mEndereco;
}

unsigned int Package::get_custo_por_quilo(){
    return mPrecoPorKg;
}

unsigned int Package::get_peso(){
    return mPeso;
}

void Package::setPeso(unsigned int peso){
    mPeso = peso;
}

void Package::setPrecoPorKg(unsigned int precoPorKg){
    mPrecoPorKg = precoPorKg;
}

void Package::setNome(std::string nome){
    mNome = nome;
}

void Package::setEndereco(std::string endereco){
    mEndereco = endereco;
}

Package::~Package(){}