#ifndef HEM_TABU_TSP_HPP
#define HEM_TABU_TSP_HPP

#include "tsp/greedy_tsp.hpp"

struct NN {
  int next;
  int cost;
  bool already_ocurred;
};

class Tabu_TSP : public Greedy_TSP {
protected:
  int path_cost;

public:
  Tabu_TSP(const std::vector<std::pair<long double, long double>> &points);
  ~Tabu_TSP();
  
  virtual void solve() override;
  virtual int cost() override;
};
  

#endif