#include<string>

class Aluno {
private:
    std::string name;
    int option1;
    int option2;
public:
    Aluno(std::string mName, int mOption1, int mOption2);
    std::string get_name();
    int get_option1();
    int get_option2();
}