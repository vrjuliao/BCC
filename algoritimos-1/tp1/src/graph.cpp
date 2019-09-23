#include "graph.hpp"

Graph::Graph(int quantity_of_players){
    mPlayers = std::vector<Person*>(quantity_of_players);
}

void Graph::add_player(int age, int index){
    Person* player = new Person();
    player->age = age;
    player->childrens = std::vector<Person*>();
    player->parents = std::vector<Person*>();
    player->index = index+1;
    mPlayers[index] = player;
}

void Graph::add_relashionship(int parent_index, int children_index){
    mPlayers[parent_index-1]->childrens.push_back(mPlayers[children_index-1]);
    mPlayers[children_index-1]->parents.push_back(mPlayers[parent_index-1]);
}

void Graph::clear_flag(){
    int size = mPlayers.size();
    for(int i = 0; i < size; i++){
        mPlayers[i]->marked = false;
    }
}

void Graph::compute_topological_sort_by_stack(Person *head_player, std::stack<Person*> &stack){
    int size = head_player->childrens.size();
    head_player->marked = true;
    for (int i = 0; i < size; i++){
        if(!head_player->childrens[i]->marked)
            compute_topological_sort_by_stack(head_player->childrens[i], stack);
    }
    stack.push(head_player);
}

bool Graph::has_cycle(Person *player, int index_of_root_player){
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

int Graph::get_lesser_parent_age(Person* player, int current_lesser_age){
    int size = player->parents.size();
    for(int i = 0; i<size; i++){
        if(player->parents[i]->marked)
            continue;
        if(current_lesser_age < player->parents[i]->age){
            current_lesser_age = get_lesser_parent_age(player->parents[i], current_lesser_age);
        } else {
            current_lesser_age = get_lesser_parent_age(player->parents[i], player->parents[i]->age);
        }
    }
    if(current_lesser_age >  player->age)
        return player->age;
    return current_lesser_age;
}

void Graph::swap(int player1_index, int player2_index){
    this->clear_flag();
    //verifying if Player1 is a parent of Player2
    std::cout << "S ";

    Person *instance_p1 = mPlayers[player1_index-1];
    Person *instance_p2 = mPlayers[player2_index-1];

    int size = instance_p1->childrens.size();
    int children_index = -1;
    for(int i =0; i<size; i++){
        if(instance_p1->childrens[i]->index == player2_index){
            children_index = i;
            break;
        }
    }

    if(children_index < 0){
        std::cout << "N" << std::endl;
        return;
    }

    //validate whether no have a cycle when add a new edge
    //pseudo change, adding the new edge
    Person *p = instance_p1->childrens[children_index];
    instance_p1->childrens[children_index] = instance_p1->childrens.back();
    instance_p1->childrens.pop_back();

    instance_p2->childrens.push_back(instance_p1);
    
    if(this->has_cycle(instance_p2, player2_index)){
        instance_p2->childrens.pop_back();
        instance_p1->childrens.push_back(p);
        std::cout << "N" << std::endl;
    } else {
        //persist changes
        //add player2 as parent of player1
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
        std::cout << "T" << std::endl;
    }
}
void Graph::meeting(){
    this->clear_flag();
    std::cout << "M";
    int size = mPlayers.size();
    std::stack<Person*> stack =  std::stack<Person*>();
    for(int i = 0; i < size; i++){
        if(mPlayers[i]->parents.size()==0){
            this->compute_topological_sort_by_stack(mPlayers[i], stack);
        }
    }
    size = stack.size();
    for(int i = 0; i < size; i++){
        std::cout << ' ' << stack.top()->index;
        stack.pop();
    }
    std::cout << std::endl;
}

void Graph::commander(int player_index){
    this->clear_flag();
    int player_age = mPlayers[player_index-1]->age;
    int lesser_age = get_lesser_parent_age(mPlayers[player_index-1], OVERFLOW_AGE);
    std::cout << "C ";
    if(lesser_age == player_age)
        std::cout << '*';
    else 
        std::cout << lesser_age;
    std::cout << std::endl;
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
