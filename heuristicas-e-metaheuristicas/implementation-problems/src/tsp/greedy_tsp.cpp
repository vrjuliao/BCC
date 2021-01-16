#include "tsp/tsp.hpp"
#include "tsp/greedy_tsp.hpp"

Greedy_TSP::Greedy_TSP(const std::vector<std::pair<long double, long double>> &points): TSP(points){}

Greedy_TSP::~Greedy_TSP(){
  mAdj_list.clear();
}

int Greedy_TSP::cost(std::function<int
      (Node, Node)> distance) {
  long double result = 0.0;
  long double local_max;
  long double dist;
  int size = mAdj_list.size();

  if(size <= 1)
    return result;

  for(int i=0; i<size-1; i++){
    local_max = distance(mAdj_list[i], mAdj_list[i+1]);
    for(int j=i+2; j<size; j++){
      dist = distance(mAdj_list[i], mAdj_list[j]);
      if(dist<local_max)
        local_max = dist;
    }
    result+=local_max;
  }
  
  return result;
};