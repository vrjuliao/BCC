#include "tsp/tsp.hpp"

TSP::TSP(const std::vector<std::pair<long double, long double>> &points){
  mAdj_list = std::vector<Node>(points.size());
  for(int i=0; i<points.size(); i++){
    mAdj_list[i] = Node{points[i].first, points[i].second, false}; 
  }
}

TSP::~TSP(){
  mAdj_list.clear();
}