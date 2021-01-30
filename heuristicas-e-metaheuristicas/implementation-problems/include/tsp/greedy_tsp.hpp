#ifndef HEM_GREEDY_TSP_INTERFACE_HPP
#define HEM_GREEDY_TSP_INTERFACE_HPP

#include <vector>
#include <utility>
#include "tsp/tsp.hpp"

class Greedy_TSP: public TSP {

public:
  Greedy_TSP(const std::vector<std::pair<long double, long double>> &points);
  ~Greedy_TSP();
  
  /*
  @description: implements the abstract method of TSP class.
                Is the greedy heuristic to yield the TSP cost.
  */
  virtual int cost(std::function<int(Node, Node)> distance) override;
};
  

#endif