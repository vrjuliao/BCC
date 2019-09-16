#include <iostream>
#include <vector>
#include <list>

struct person{
    int index;
    int age;
    bool marked;
    std::list<person*> childrens;
};

int main(){
    int prsn_count, rlshp_count, instr_count;
    //person count, relashionship count and instructions count.

    std::cin >> prsn_count >> rlshp_count >> instr_count;
    std::vector<person*> players = std::vector<person*>(prsn_count);

    for (int i = 0; i < prsn_count; i++){
        person *player = new person();
        player->childrens = std::list<person*>();
        std::cin >> player->age;
        players[i] = player;

    }

    int parent, children;
    for(int i = 0; i<rlshp_count; i++){
        std::cin.ignore();
        std::cin >> parent;
        std::cin >> children;
        players[parent-1]->childrens.push_back(players[children-1]);
    }
 

    //clearing allocations
    for(int i = 0; i < prsn_count; i++){
        players[i]->childrens.clear();
        delete players[i];
    }
    players.clear();


    return 0;
}