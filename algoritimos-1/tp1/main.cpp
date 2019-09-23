#include <iostream>
#include <string>
#include <chrono>

#include "graph.hpp"

int main(int argc, const char *argv[]){
    
    //getting parameter whether time must be show
    bool show_time = false;
    if(argc > 1){
        std::string param = "-t";
        if(argv[1] == param){
            show_time = true;
        }
    }

    //time manipulators
    std::chrono::high_resolution_clock::time_point t1;
    std::chrono::high_resolution_clock::time_point t2;
    std::chrono::duration<double, std::micro> elapsed_time;


    //init time
    t1 = std::chrono::high_resolution_clock::now();
    
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
                if(show_time)
                    t1 = std::chrono::high_resolution_clock::now();
                graph.commander(value1);
                break;
            case 'M':
                if(show_time)
                    t1 = std::chrono::high_resolution_clock::now();
                graph.meeting();
                break;
            case 'S':
                std::cin >> value1 >> value2;
                if(show_time)
                    t1 = std::chrono::high_resolution_clock::now();
                graph.swap(value1, value2);
                break;
        }
        if(show_time){
            t2 = std::chrono::high_resolution_clock::now();
            elapsed_time = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
            std::cout << "Time in nanoseconds: " << static_cast<unsigned int>(elapsed_time.count());
            std::cout << std::endl << std::endl;
        }
    }
    return 0;
}