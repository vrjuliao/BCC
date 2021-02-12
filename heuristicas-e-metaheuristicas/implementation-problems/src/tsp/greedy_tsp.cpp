#include "tsp/tsp.hpp"
#include "tsp/greedy_tsp.hpp"
#include <cstdlib>
#include <ctime>

Greedy_TSP::Greedy_TSP(const std::vector<std::pair<long double, long double>> &points): TSP(points){
  this->path = std::vector<Node>(this->mAdj_list.size());
}

Greedy_TSP::~Greedy_TSP(){
  mAdj_list.clear();
}

int Greedy_TSP::cost() {

  int result = 0, size = mAdj_list.size();

  for (int i=1; i<size; i++){
    result+=this->distance(this->path[i-1], this->path[i]);
  }

  // To complete the cycle, it's necessary add the cost of the edge
  //   between the last and first visited node.
  result += this->distance(this->path[size-1], this->path[0]);
  return result;
}

void Greedy_TSP::solve() {

  int local_max, dist, size = mAdj_list.size();

  if(size == 0)
    return;

  // The first visited node is selected randomly
  std::srand(time(NULL));
  int first = std::rand()%size;

  int i, j, next, curr = first;
  mAdj_list[curr].visited = true;
  this->path[0] = mAdj_list[curr];
  
  for(i=1; i<size; i++){
    // search the first available node
    for(j=0; mAdj_list[j].visited; j++){}
    next = j;
    local_max = this->distance(mAdj_list[curr], mAdj_list[next]);
    
    // check if there is another available node less distant than *next*
    for(j+=1;j<size; j++){
      if(!mAdj_list[j].visited){
        dist = this->distance(mAdj_list[curr], mAdj_list[j]);
        if(dist<local_max){
          local_max = dist;
          next = j;
        }
      }
    }

    // the cheaper availabe node from *curr* node will be the new *curr*
    mAdj_list[next].visited = true;
    curr = next;
    this->path[i] = mAdj_list[next];
  }
  this->is_solved = true;
}