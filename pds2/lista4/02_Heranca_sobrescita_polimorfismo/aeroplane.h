#ifndef AEROPLANE_H_
#define AEROPLANE_H_
#include <string>

class Aeroplane {
	public:
	    //Aeroplane(std::string, int, int, int, float, float, std::string);
	    Aeroplane(std::string, int, int, int, float, float, int);
		virtual int fly();
		int get_number_of_passengers();
		float get_top_speed();
		int get_number_of_turbines();
		float get_autonomy();
		int get_size();
		std::string get_name();
		virtual ~Aeroplane();


	protected:
		int number_of_turbines;
		int size_in_meters;
		float autonomy_in_kilometers;
		float top_speed;
		int number_of_passengers;
		int current_speed;
		std::string name;
		//std::string company;

};

#endif /* AEROPLANE_H_ */
