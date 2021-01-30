#include "tsp/tsp.hpp"
#include "tsp/greedy_tsp.hpp"
#include <cstdlib>
#include <ctime>

Greedy_TSP::Greedy_TSP(const std::vector<std::pair<long double, long double>> &points): TSP(points){}

Greedy_TSP::~Greedy_TSP(){
  mAdj_list.clear();
}

int Greedy_TSP::cost(std::function<int
    (Node, Node)> distance) {

  int local_max, dist,
    result = 0, size = mAdj_list.size();

  if(size <= 1)
    return result;

  // The first visited node is selected randomly
  std::srand(time(NULL));
  int first = std::rand()%size;

  int i, j, next, curr = first;
  mAdj_list[curr].visited = true;
  for(i=0; i<size-1; i++){
    // search the first available node
    for(j=0; mAdj_list[j].visited; j++){}
    next = j;
    local_max = distance(mAdj_list[curr], mAdj_list[next]);
    
    // check if there is another available node less distant than *next*
    for(j+=1;j<size; j++){
      if(!mAdj_list[j].visited){
        dist = distance(mAdj_list[curr], mAdj_list[j]);
        if(dist<local_max){
          local_max = dist;
          next = j;
        }
      }
    }

    // the cheaper availabe node from *curr* node will be the new *curr*
    mAdj_list[next].visited = true;
    curr = next;
    result+=local_max;
  }

  // To complete the cycle, it's necessary add the cost of the edge
  //   between the last and first visited node.
  result += distance(mAdj_list[first], mAdj_list[curr]);
  return result;
};