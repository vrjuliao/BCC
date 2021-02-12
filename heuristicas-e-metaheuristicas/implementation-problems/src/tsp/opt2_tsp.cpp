#include "tsp/opt2_tsp.hpp"
#include <vector>
#include <utility>
#include <algorithm>
#include <iterator>


Opt2_TSP::Opt2_TSP(const std::vector<std::pair<long double, long double>> &points): Greedy_TSP(points){}

int Opt2_TSP::distance_of(const std::vector<Node> &route){

  int result = 0, size = route.size();

  for (int i=1; i<size; i++){
    result+=this->distance(route[i-1], route[i]);
  }
  result += this->distance(route[size-1], route[0]);
  return result;
}


void Opt2_TSP::solve(){
  Greedy_TSP::solve();
  int size = this->path.size();
  bool improved = true;
  while(improved)  {
    improved = false;
    for(int i=1; i<size-2; i++){
      for (int j = i+1; j<size; j++){
        if (j-i == 1)
          continue;
        
        std::vector<Node> new_path(this->path);

        // 2opt swap method
        for(int k=0; (k+i)<j; k++){
          new_path[k+i] = this->path[j-k-1];
        }

        if (distance_of(new_path) < this->cost()){
          this->path = new_path;
          improved = true;
        }
      }
    }
  }
}