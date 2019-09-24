#include <iostream>
#include <string>
#include <chrono>

#include "graph.hpp"

void print_commander(int age){
    std::cout << "C ";
    if(age == OVERFLOW_AGE)
        std::cout << '*';
    else
        std::cout << age;
}

void print_swap(char swap_response){
    std::cout << "S " << swap_response;
}

void print_meeting(std::vector<int> &topological_sort){
    std::cout << 'M';
    int size = topological_sort.size();
    for(int i =0; i<size; i++)
        std::cout << ' ' << topological_sort[i];
}

int main(int argc, const char *argv[]){
    
    //getting parameter whether time must be show
    bool show_time, show_both = false;
    if(argc > 1){
        std::string param_time = "-t";
        std::string param_both = "-b";
        show_both = param_both == argv[1];
        show_time = param_time == argv[1];
    }

    //time manipulators
    std::chrono::high_resolution_clock::time_point t1;
    std::chrono::high_resolution_clock::time_point t2;
    std::chrono::duration<double, std::micro> elapsed_time;

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

    //return receivers
    std::vector<int> topological_sort = std::vector<int>(prsn_count);
    char change_hierarquical;
    int lesser_parent_age;
    double execution_time;

    char instruction;
    int value1, value2;
    for(int i = 0; i < instr_count; i++){
        std::cin >> instruction;
        switch(instruction){
            case 'C':
                std::cin >> value1;
                t1 = std::chrono::high_resolution_clock::now();
                lesser_parent_age = graph.commander(value1);
                t2 = std::chrono::high_resolution_clock::now();
                if(!show_time) print_commander(lesser_parent_age);
                break;
            case 'M':
                t1 = std::chrono::high_resolution_clock::now();
                graph.meeting(topological_sort);
                t2 = std::chrono::high_resolution_clock::now();
                if(!show_time) print_meeting(topological_sort);
                break;
            case 'S':
                std::cin >> value1 >> value2;
                t1 = std::chrono::high_resolution_clock::now();
                change_hierarquical = graph.swap(value1, value2);
                t2 = std::chrono::high_resolution_clock::now();
                if(!show_time) print_swap(change_hierarquical);
                break;
        }
        if(show_time || show_both){
            t2 = std::chrono::high_resolution_clock::now();
            elapsed_time = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
            execution_time = static_cast<unsigned int>(elapsed_time.count());
            if(show_both)
                std::cout << " ----- Time in nanoseconds: ";
            std::cout<< execution_time;
        }
        std::cout << std::endl;
    }
    return 0;
}