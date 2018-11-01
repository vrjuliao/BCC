#include "fighteraircraft.h"
#include <iostream>
#include <string>

Fighter_Aircraft::Fighter_Aircraft(std::string name, int number_of_passengers, int number_of_turbines, int size_in_meters, float autonomy_in_kilometers, float top_speed, int number_of_missiles):
Aeroplane::Aeroplane(name, number_of_passengers, number_of_turbines, size_in_meters, autonomy_in_kilometers, top_speed, 0)
{
	this->number_of_missiles = number_of_missiles;
}


void Fighter_Aircraft::shoot() {
	this->number_of_missiles = number_of_missiles-1;
}

int Fighter_Aircraft::get_number_of_missiles() {
	return this->number_of_missiles;
}

void Fighter_Aircraft::shoot(int number_of_missiles_to_fire) {
	this->number_of_missiles = this->number_of_missiles - number_of_missiles_to_fire;
}


void Fighter_Aircraft::fly_at_max_speed() {
	current_speed = top_speed;
}


int Fighter_Aircraft::fly() {
	current_speed = number_of_turbines*700;
	if (current_speed > top_speed) {
		current_speed = top_speed;
	}

	return current_speed;
}

Fighter_Aircraft::~Fighter_Aircraft(){}
/*int Fighter_Aircraft::fly() {
	current_speed = number_of_turbines*(700 + size_in_meters);
	return current_speed;
}*/

