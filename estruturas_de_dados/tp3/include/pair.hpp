#ifndef PAIR_TP3
#define PAIR_TP3

#include <string>

// Record a data and the respective key to use a dict
class Pair {
private:
	std::string mKey;
	char mData;
public:
	//create a pair with initial data
	Pair(std::string key, char data);
	//create a pair with empty data
	Pair();
	void set_key(std::string key);
	void set_data(char data);
	std::string get_key() const;
	char get_data() const;
	~Pair();
};

#endif