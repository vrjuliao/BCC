#ifndef PAIR_TP3
#define PAIR_TP3
class Pair {
private:
	std::string mKey;
	char mData;
public:
	Pair(std::string key, char data);
	std::string get_key();
	char get_data();
	~Pair();
};

#endif