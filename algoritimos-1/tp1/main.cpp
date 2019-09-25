#include <iostream>
#include <string>
#include <chrono>

#include "graph.hpp"

// receive the age of a player and print according described in work documentation
void print_commander(int age){
    std::cout << "C ";
    if(age == OVERFLOW_AGE)
        std::cout << '*';
    else
        std::cout << age;
}

// receive the swap command response of two vetex at the graph
void print_swap(char swap_response){
    std::cout << "S " << swap_response;
}

//receive a vector containning the topological sort and print it.
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
    //instance of a timer that compute in nanoseconds
    std::chrono::duration<double, std::nano> elapsed_time;

    //Person count, relashionship count and instructions count.
    int prsn_count, rlshp_count, instr_count;

    std::cin >> prsn_count >> rlshp_count >> instr_count;
    Graph graph = Graph(prsn_count);
    
    // reading the age of each player
    int age;
    for (int i = 0; i < prsn_count; i++){
        std::cin >> age;
        graph.add_player(age, i);
    }

    //reading relashionships
    int parent, children;
    for(int i = 0; i<rlshp_count; i++){
        std::cin.ignore();
        std::cin >> parent;
        std::cin >> children;
        graph.add_relashionship(parent, children);
    }

    //returner variables of each command 
    std::vector<int> topological_sort = std::vector<int>(prsn_count);
    char change_hierarquical;
    int lesser_parent_age;
    double execution_time;

    // reading each command (Swap, Commander and Meeting)
    char instruction;
    int value1, value2;
    for(int i = 0; i < instr_count; i++){
        std::cin >> instruction;

        //define who command must be executed
        switch(instruction){
            //getting (Commander)
            case 'C':
                std::cin >> value1;
                t1 = std::chrono::high_resolution_clock::now();
                lesser_parent_age = graph.commander(value1);
                t2 = std::chrono::high_resolution_clock::now();
                if(!show_time) print_commander(lesser_parent_age);
                break;

            //getting Swap
            case 'S':
                std::cin >> value1 >> value2;
                t1 = std::chrono::high_resolution_clock::now();
                change_hierarquical = graph.swap(value1, value2);
                t2 = std::chrono::high_resolution_clock::now();
                if(!show_time) print_swap(change_hierarquical);
                break;

            //getting Meeting
            case 'M':
                t1 = std::chrono::high_resolution_clock::now();
                graph.meeting(topological_sort);
                t2 = std::chrono::high_resolution_clock::now();
                if(!show_time) print_meeting(topological_sort);
                break;
        }
        // switch if is necessary to print the time of each execution
        if(show_time || show_both){
            elapsed_time = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
            execution_time = static_cast<unsigned int>(elapsed_time.count());
            if(show_both)
                std::cout << " ----- Time in nanoseconds: ";
            std::cout << execution_time;
        }
        std::cout << std::endl;
    }
    return 0;
}