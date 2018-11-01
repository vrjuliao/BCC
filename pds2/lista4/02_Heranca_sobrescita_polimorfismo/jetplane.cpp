#include "jetplane.h"
#include <string>

Jet_Plane::Jet_Plane(std::string name, int number_of_passengers, int number_of_turbines, int size_in_meters, float autonomy_in_kilometers, float top_speed, std::string company):
Aeroplane::Aeroplane(name, number_of_passengers, number_of_turbines, size_in_meters, autonomy_in_kilometers, top_speed, 0){
	this->company = company;
}

void Jet_Plane::stop_and_get_passengers(int number_of_extra_passengers) {
	number_of_passengers+= number_of_extra_passengers;
}

std::string Jet_Plane::get_company() {
	return company;
}

void Jet_Plane::fly_with_max_capacity() {
	current_speed = top_speed/3;
}

int Jet_Plane::fly() {
	current_speed = number_of_turbines*300;
	if (current_speed > top_speed) {
		current_speed = top_speed;
	}

	return current_speed;
}

Jet_Plane::~Jet_Plane(){}

/*int Jet_Plane::fly() {
	current_speed = number_of_turbines*(300+size_in_meters)*(number_of_passengers/500);
	return current_speed;
}*/
