#ifndef LISTA3_EX3_TWODAYPACKAGE
#define LISTA3_EX3_TWODAYPACKAGE
#include <string>
#include "package.h"

class TwoDayPackage : public Package {
private:
    unsigned int mTaxaFixa;
public:
    TwoDayPackage(unsigned int, unsigned int, unsigned int, std::string, std::string);
    virtual double calculate_cost();
    virtual ~TwoDayPackage();
};

#endif