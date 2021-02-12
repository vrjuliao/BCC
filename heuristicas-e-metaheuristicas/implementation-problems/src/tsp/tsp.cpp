#include "tsp/tsp.hpp"

TSP::TSP(const std::vector<std::pair<long double, long double>> &points){
  mAdj_list = std::vector<Node>(points.size());
  for(int i=0; i<points.size(); i++){
    mAdj_list[i] = Node{points[i].first, points[i].second, false}; 
  }
  this->is_solved = false;
}

TSP::~TSP(){
  mAdj_list.clear();
}

void TSP::set_distance_function(std::function<int(Node, Node)> distance){
  this->distance = distance;
}

std::vector<Node> TSP::get_route(){
  return this->path;
}