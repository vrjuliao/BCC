#include "fleet.h"
#include <string>
#include <iostream>
#include <vector>

std::vector<Aeroplane *> Fleet::instantiate_fleet(int number_of_planes) {
    
	std::vector<Aeroplane*> mFleet;
	
    Aeroplane *concorde = new Jet_Plane("Concorde", 580, 5, 62, 12000.8, 2179.2, "British Aircraft Corporation");
	Aeroplane *f22 = new Fighter_Aircraft("F22", 2, 5, 22, 2000.0, 2414.016, 8);
	Aeroplane *f16 = new Fighter_Aircraft("F16", 1, 3, 19, 3015.6, 2830.50, 12);
	Aeroplane *su_27 = new Fighter_Aircraft("SU-27", 1, 7, 20, 3030.2, 7200, 12);
	Aeroplane *f_12 = new Fighter_Aircraft("F12", 1, 3, 18.3, 1812.2, 2329.2, 6.5);
	Aeroplane *boeing777 = new Jet_Plane("Boeing 777", 300, 2, 35, 4000.2, 870.5, "LATAM");
	Aeroplane *a380 = new Jet_Plane("AirBus 380", 420, 3, 40, 3750.7, 700.89, "Air France");
	Aeroplane *hercules = nullptr;
	Jet_Plane *antonov = nullptr;
    
    if (number_of_planes > 6) {
        //Aeroplane mryia_antonov("Antonov An-225", 1280, 10, 84, 14003.35, 450.80, "Mryia Cargo");
        Jet_Plane *mryia_antonov = new Jet_Plane("Antonov An-225", 1280, 10, 84, 14003.35, 450.80, "Mryia Cargo");
        antonov = mryia_antonov;
    }
    
    mFleet.push_back(concorde);
    mFleet.push_back(f22);
    mFleet.push_back(f16);
    mFleet.push_back(su_27);
    mFleet.push_back(boeing777);
    mFleet.push_back(a380);
    mFleet.push_back(antonov);
    mFleet.push_back(hercules);
    mFleet.push_back(f_12);
    
    return mFleet;
}

void Fleet::print_fleet_data(std::vector<Aeroplane*> &fleet) {
    Aeroplane* aux;
    for (unsigned int i=0; i < fleet.size(); i++) {
        if(fleet[i] != nullptr){
            std::cout << "Plane name: "<< fleet[i]->get_name() << std::endl;
		    std::cout << "Current speed: "<< fleet[i]->fly() << std::endl;
		    std::cout << "Top speed: "<< fleet[i]->get_top_speed() << std::endl;
		    std::cout << "Autonomy: "<< fleet[i]->get_autonomy() << std::endl;
		    std::cout << "Number of passengers: "<< fleet[i]->get_number_of_passengers() << std::endl;
		    std::cout << "Number of Turbines: " << fleet[i]->get_number_of_turbines() << std::endl;

    		if (Fighter_Aircraft* aircraft = dynamic_cast<Fighter_Aircraft*>(fleet[i])){
			    std:: cout << "Number of missiles: " << aircraft->get_number_of_missiles() << std::endl;
			    aircraft->shoot();
		        std:: cout << "Number of missiles: " << aircraft->get_number_of_missiles() << std::endl;
		        delete aircraft;
		    } else {
		        aux = fleet[i];
		        delete aux;    
		    }
		    std::cout << std::endl;
        }
	}
	fleet.clear();
}

Fleet::~Fleet() {
   /* Aeroplane *aux;
    for (unsigned int i=0; i < mFleet.size(); i++) {
        aux = mFleet[i];
        
        if(mFleet[i] != nullptr && mFleet[i] != NULL){
            delete aux;
        
            if (Fighter_Aircraft* aircraft = dynamic_cast<Fighter_Aircraft*>(aux)){
                delete aircraft;
            } else if(Jet_Plane* jet = dynamic_cast<Jet_Plane*>(aux)){
                delete jet;
            } else {
                delete aux;
            }
        
        }
	}
	mFleet.clear();
	*/
}