#include "graph.hpp"

Graph::Graph(int quantity_of_players){
    mPlayers = std::vector<Vertex*>(quantity_of_players);
}

void Graph::add_player(int age, int index){
    //Allocate memory and instanciate the properties
    Vertex* player = new Vertex();
    player->age = age;
    player->childrens = std::vector<Vertex*>();
    player->parents = std::vector<Vertex*>();
    player->index = index+1;
    mPlayers[index] = player;
}

void Graph::add_relashionship(int parent_index, int children_index){
    //create edges on the normal graph and on the reverse graph
    mPlayers[parent_index-1]->childrens.push_back(mPlayers[children_index-1]);
    mPlayers[children_index-1]->parents.push_back(mPlayers[parent_index-1]);
}

void Graph::clear_flag(){
    int size = mPlayers.size();
    for(int i = 0; i < size; i++){
        mPlayers[i]->marked = false;
    }
}

//DFS to push the vertex at the end of visit
void Graph::compute_topological_sort_by_stack(Vertex *head_player, std::stack<Vertex*> &stack){
    int size = head_player->childrens.size();
    head_player->marked = true;
    for (int i = 0; i < size; i++){
        if(!head_player->childrens[i]->marked)
            compute_topological_sort_by_stack(head_player->childrens[i], stack);
    }
    stack.push(head_player);
}

bool Graph::has_cycle(Vertex *player, const int index_of_root_player){
    // check if player is the root player called on begin of recursion
    if(player->marked){
        if(index_of_root_player == player->index)
            return true;
        else 
            return false;
    }
    //run DFS to check whether graph has a cycle between children nodes
    player->marked = true;
    int size = player->childrens.size();
    bool cycle = false;
    for(int i = 0; i < size && !cycle; i++){
        cycle = this->has_cycle(player->childrens[i], index_of_root_player);
    }
    return cycle;
}

int Graph::get_lesser_parent_age(Vertex* player, int current_lesser_age){
    int size = player->parents.size();
    //Run DFS to navigate arround the graph
    for(int i = 0; i<size; i++){
        if(player->parents[i]->marked)
            continue;
        //check if found a age lesser than current age
        if(current_lesser_age < player->parents[i]->age){
            current_lesser_age = get_lesser_parent_age(player->parents[i], current_lesser_age);
        } else {
            current_lesser_age = get_lesser_parent_age(player->parents[i], player->parents[i]->age);
        }
    }
    return current_lesser_age;
}

char Graph::swap(int player1_index, int player2_index){
    this->clear_flag();
    
    //verifying if Player1 is a parent of Player2
    Vertex *instance_p1 = mPlayers[player1_index-1];
    Vertex *instance_p2 = mPlayers[player2_index-1];

    int size = instance_p1->childrens.size();
    int children_index = -1;
    
    //check if there is an edge between player1 and player2
    for(int i =0; i<size; i++){
        if(instance_p1->childrens[i]->index == player2_index){
            children_index = i;
            break;
        }
    }

    // player2 is not a children from player1
    if(children_index < 0){
        return 'N';
    }

    //validate whether no have a cycle when add a new edge
    //pseudo change, adding the new edge

    //saving instance of children in <p>
    Vertex *p = instance_p1->childrens[children_index];
    // put the last children element of player1 in <p> index
    instance_p1->childrens[children_index] = instance_p1->childrens.back();
    //delete the last children element, because it is redundant
    instance_p1->childrens.pop_back();

    //add player1 as a children of player2
    instance_p2->childrens.push_back(instance_p1);
    char return_char;

    if(this->has_cycle(instance_p2, player2_index)){
        // Undo change of edge direction
        instance_p2->childrens.pop_back();
        instance_p1->childrens.push_back(p);
        return_char = 'N';

    } else {
        //persist changes
        //add player2 as a parent of player1
        size = instance_p2->parents.size();
        int parent_index = -1;
        for(int i = 0; i < size; i++){
            if(instance_p2->parents[i]->index == instance_p1->index){
                p = instance_p2->parents[i];
                parent_index = i;
                break;
            }
        }
        instance_p2->parents[parent_index] = instance_p2->parents.back();
        instance_p2->parents.pop_back();

        instance_p1->parents.push_back(instance_p2);
        return_char =  'T';
    }
    return return_char;
}

void Graph::meeting(std::vector<int> &sort){
    this->clear_flag();

    // call computation of topological sort for each vertex that's does not have parents
    int size = mPlayers.size();
    std::stack<Vertex*> stack =  std::stack<Vertex*>();
    for(int i = 0; i < size; i++){
        if(mPlayers[i]->parents.size()==0){
            this->compute_topological_sort_by_stack(mPlayers[i], stack);
        }
    }

    // put each vertex index value in vector of parameters
    size = stack.size();
    for(int i = 0; i < size; i++){
        sort[i] = stack.top()->index;
        stack.pop();
    }
}

int Graph::commander(int player_index){
    this->clear_flag();
    int player_age = mPlayers[player_index-1]->age;
    
    //run DFS using reverse graph from player got in pararameters
    int lesser_age = get_lesser_parent_age(mPlayers[player_index-1], OVERFLOW_AGE);
    if(lesser_age == player_age)
        return OVERFLOW_AGE;
    return lesser_age;
}

Graph::~Graph(){
    int size = mPlayers.size();
    for(int i = 0; i < size; i++){
        mPlayers[i]->childrens.clear();
        mPlayers[i]->parents.clear();
        delete mPlayers[i];
    }
    mPlayers.clear();
}
