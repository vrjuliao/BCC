#ifndef HEM_OPT2_TSP_HPP
#define HEM_OPT2_TSP_HPP

#include "tsp/greedy_tsp.hpp"

class Opt2_TSP: public Greedy_TSP {
private:
  int distance_of(const std::vector<Node> &route);

public:
  Opt2_TSP(const std::vector<std::pair<long double, long double>> &points);
  
  /*
  @description: implements the abstract method of TSP class.
                Is the greedy heuristic to yield the TSP cost.
  */

  virtual void solve() override;
};
#endif