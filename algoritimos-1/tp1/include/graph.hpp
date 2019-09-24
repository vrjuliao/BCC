#ifndef GRAPH_ALG1_TP1
#define GRAPH_ALG1_TP1

#include <iostream>
#include <vector>
#include <list>
#include <stack>


struct Person{
    int index;
    int age;
    bool marked;
    std::vector<Person*> parents;
    std::vector<Person*> childrens;
};

static const int OVERFLOW_AGE = 101;

class Graph {
private:
    std::vector<Person *> mPlayers;

    void clear_flag();
    void compute_topological_sort_by_stack(Person *player, std::stack<Person*> &stack);
    bool has_cycle(Person *player, int index_of_root_player);
    int get_lesser_parent_age(Person* player, int current_lesser_age);
public:
    Graph(int quantity_of_players);
    char swap(int player1_index, int player2_index);
    void meeting(std::vector<int> &sort);
    int commander(int player_index);
    void add_relashionship(int parent_index, int children_index);
    void add_player(int age, int index);
    ~Graph();
};
#endif