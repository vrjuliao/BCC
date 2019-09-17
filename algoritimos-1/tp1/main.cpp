#include <iostream>
#include <vector>
#include <list>

static const int OVERFLOW_AGE = 101;

struct Person{
    int index;
    int age;
    bool marked;
    std::vector<Person*> parents;
    std::vector<Person*> childrens;
};

void print_order_by_person(Person *player){
    std::list<Person*> bfs_queue = std::list<Person*>();
    bfs_queue.push_back(player);
    Person *current_player;
    int qtt_children;
    while(bfs_queue.size() > 0){
        current_player = bfs_queue.front();
        bfs_queue.pop_front();
        if(!current_player->marked){
            current_player->marked = true;
            std::cout << ' ' << current_player->index;
            qtt_children = current_player->childrens.size();
            for(int i = 0; i < qtt_children; i++){
                bfs_queue.push_back(current_player->childrens[i]);
            }
        }
    }
}

// void print_order(std::vector<Person*> &graph){
//     int size = graph.size();
//     for(int i=0; i < size; i++){
//         if(!graph[i]->marked && graph[i]->parents.size()==0)
//             print_order_by_person(graph[i]);
//     }
// }

bool has_cicle(Person* player){
    //run DFS to check whether graph has a cicle
    
    if(player->marked)
        return true;

    player->marked = true;
    int size = player->childrens.size();
    bool cicle = false;
    for(int i = 0; i < size && !cicle; i++){
        cicle = has_cicle(player->childrens[i]);
    }
    return cicle;
}

int get_lesser_parent_age(Person* player, int current_lesser_age){
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

void clear_flags(std::vector<Person*> &players){
    int size = players.size();
    for(int i = 0; i < size; i++){
        players[i]->marked = false;
    }
}

void commander(std::vector<Person*> &players, int player_index){
    int player_age = players[player_index-1]->age;
    int lesser_age = get_lesser_parent_age(players[player_index-1], OVERFLOW_AGE);
    std::cout << "C ";
    if(lesser_age == player_age)
        std::cout << '*';
    else 
        std::cout << lesser_age;
    std::cout << std::endl;
}

void swap(std::vector<Person*> &players, int player1, int player2){
    //verifying if Player1 is a parent of Player2
    std::cout << "S ";

    Person *instance_p1 = players[player1-1];
    Person *instance_p2 = players[player2-1];

    int size = instance_p1->childrens.size();
    int children_index = -1;
    for(int i =0; i<size; i++){
        if(instance_p1->childrens[i]->index == player2){
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
    
    if(has_cicle(instance_p2)){
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

void meeting(std::vector<Person*> &players){
    std::cout << 'M';
    int size = players.size();
    
    for(int i = 0; i < size; i++){
        if(players[i]->parents.size()==0){
            print_order_by_person(players[i]);
        }
    }
    std::cout << std::endl;
}

int main(){
    int prsn_count, rlshp_count, instr_count;
    //Person count, relashionship count and instructions count.

    std::cin >> prsn_count >> rlshp_count >> instr_count;
    std::vector<Person*> players = std::vector<Person*>(prsn_count);

    for (int i = 0; i < prsn_count; i++){
        Person *player = new Person();
        player->childrens = std::vector<Person*>();
        std::cin >> player->age;
        player->index = i+1;
        players[i] = player;
    }

    int parent, children;
    for(int i = 0; i<rlshp_count; i++){
        std::cin.ignore();
        std::cin >> parent;
        std::cin >> children;
        players[parent-1]->childrens.push_back(players[children-1]);
        players[children-1]->parents.push_back(players[parent-1]);
    }
 
    char instruction;
    int value1, value2;
    for(int i = 0; i < instr_count; i++){
        clear_flags(players);
        std::cin >> instruction;
        switch(instruction){
            case 'C':
                std::cin >> value1;
                commander(players, value1);
                break;
            case 'M':
                meeting(players);
                break;
            case 'S':
                std::cin >> value1 >> value2;
                swap(players, value1, value2);
                break;
        }
        // std::cout << "-----" << std::endl;
    }

    //clearing allocations
    for(int i = 0; i < prsn_count; i++){
        players[i]->childrens.clear();
        players[i]->parents.clear();
        delete players[i];
    }
    players.clear();


    return 0;
}