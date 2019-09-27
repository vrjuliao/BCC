#ifndef GRAPH_ALG1_TP1
#define GRAPH_ALG1_TP1

#include <iostream>
#include <vector>
#include <stack>


struct Vertex{
    int index;
    int age;
    bool marked;
    std::vector<Vertex*> parents;
    std::vector<Vertex*> childrens;
};

static const int OVERFLOW_AGE = 101;

class Graph {
private:
    std::vector<Vertex *> mPlayers;
    
    // set all Vertex->marked tp false in vector mPlayers
    void clear_flag(); 
    
    // recursively, using a auxiliar structure of stack get the DAG topological sort
    void compute_topological_sort_by_stack(Vertex *player, std::stack<Vertex*> &stack);

    // Let of root player, check in a DFS algorithm if is possible visit root player two times
    bool has_cycle(Vertex *player, const int index_of_root_player);

    // Using the DFS algorithm, use the reverse graph (Vertex->parent) to compute the lesser age found
    int get_lesser_parent_age(Vertex* player, int current_lesser_age);
public:
    // Initialize the vector mPlayers with the quantity of players
    Graph(int quantity_of_players);

    // Call methods to swap the direction of an edge and return 'T' or 'N' if possible or not respectively
    char swap(int player1_index, int player2_index);

    // Call methods to compute the topological sort of the graph and put the index of each Vertex in the parameter vector
    void meeting(std::vector<int> &sort);

    // Compute the lesse age of parents of a Vertex
    int commander(int player_index);

    // Insert a new hierarquical order in the graph (a new directional edge)
    void add_relashionship(int parent_index, int children_index);

    // Insert a new player in the graph (a new vertex)
    void add_player(int age, int index);

    //destructor
    ~Graph();
};
#endif