#ifndef LISTA3_EX3_PACKAGE
#define LISTA3_EX3_PACKAGE
#include <string>

class Package {
private:
    std::string mEndereco, mNome;
    unsigned int mPeso, mPrecoPorKg;
public:
    Package(unsigned int, unsigned int, std::string, std::string);
    virtual double calculate_cost();
    virtual unsigned int get_peso();
    virtual std::string getNome();
    virtual std::string getEndereco();
    virtual unsigned int get_custo_por_quilo();
    virtual void setPeso(unsigned int);
    virtual void setPrecoPorKg(unsigned int);
    virtual void setNome(std::string);
    virtual void setEndereco(std::string);  
    virtual ~Package();
};

#endif