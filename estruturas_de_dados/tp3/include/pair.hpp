#ifndef PAIR_TP3
#define PAIR_TP3

#include <string>

class Pair {
private:
	std::string mKey;
	char mData;
public:
	Pair(std::string key, char data);
	Pair();
	std::string get_key() const;
	void set_key(std::string key);
	void set_data(char data);
	char get_data() const;
	~Pair();
};

#endif