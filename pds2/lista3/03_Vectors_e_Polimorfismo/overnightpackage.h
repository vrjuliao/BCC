#ifndef LISTA3_EX3_OVERNIGHTPACKACGE
#define LISTA3_EX3_OVERNIGHTPACKACGE
#include <string>
#include "package.h"

class OverNightPackage : public Package {
private:
    unsigned int mTaxaPorKg;
public:
    OverNightPackage(unsigned int, unsigned int, unsigned int, std::string, std::string);
    virtual double calculate_cost();
    virtual ~OverNightPackage();
};

#endif