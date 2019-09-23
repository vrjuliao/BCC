#include <iostream>
#include <chrono>

#include "graph.hpp"

int main(){
    //time manipulators
    std::chrono::high_resolution_clock::time_point t1;
    std::chrono::high_resolution_clock::time_point t2;
    std::chrono::duration<double, std::micro> elapsed_time;


    //init time
    t1 = std::chrono::high_resolution_clock::now();
    //sort vector
    
    //end time
    t2 = std::chrono::high_resolution_clock::now();
    //difference between init and end time
    elapsed_time = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);



    //Person count, relashionship count and instructions count.
    int prsn_count, rlshp_count, instr_count;

    std::cin >> prsn_count >> rlshp_count >> instr_count;
    // std::vector<Person*> players = std::vector<Person*>(prsn_count);
    Graph graph = Graph(prsn_count);
    int age;
    for (int i = 0; i < prsn_count; i++){
        std::cin >> age;
        graph.add_player(age, i);
    }

    int parent, children;
    for(int i = 0; i<rlshp_count; i++){
        std::cin.ignore();
        std::cin >> parent;
        std::cin >> children;
        graph.add_relashionship(parent, children);
    }
 
    char instruction;
    int value1, value2;
    for(int i = 0; i < instr_count; i++){
        std::cin >> instruction;
        switch(instruction){
            case 'C':
                std::cin >> value1;
                graph.commander(value1);
                break;
            case 'M':
                graph.meeting();
                break;
            case 'S':
                std::cin >> value1 >> value2;
                graph.swap(value1, value2);
                break;
        }
    }
    return 0;
}