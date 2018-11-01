#include "aeroplane.h"
#include <string>

/*Aeroplane::Aeroplane(std::string name, int number_of_passengers, int number_of_turbines, int size_in_meters, float autonomy_in_kilometers, float top_speed, std::string company){
    this->number_of_turbines = number_of_turbines;
    this->size_in_meters = size_in_meters;
	this->autonomy_in_kilometers = autonomy_in_kilometers;
	this->top_speed = top_speed;
	this->number_of_passengers = number_of_passengers;
	this->current_speed = current_speed;
	this->name =name;
	this->company = company;
}
*/

Aeroplane::Aeroplane(std::string name, int number_of_passengers, int number_of_turbines, int size_in_meters, float autonomy_in_kilometers, float top_speed, int current_speed){
    this->number_of_turbines = number_of_turbines;
    this->size_in_meters = size_in_meters;
	this->autonomy_in_kilometers = autonomy_in_kilometers;
	this->top_speed = top_speed;
	this->number_of_passengers = number_of_passengers;
	this->current_speed = current_speed;
	this->name =name;
}

int Aeroplane::get_number_of_passengers() {
	return number_of_passengers;
}
		
float Aeroplane::get_top_speed() {
	return top_speed;
}
		
int Aeroplane::get_number_of_turbines() {
	return number_of_turbines;
}
		
float Aeroplane::get_autonomy() {
	return autonomy_in_kilometers;
}
		
int Aeroplane::get_size() {
	return size_in_meters;
}

std::string Aeroplane::get_name() {
	return name;
}

int Aeroplane::fly() {
    return current_speed = 300;   
}

Aeroplane::~Aeroplane(){}