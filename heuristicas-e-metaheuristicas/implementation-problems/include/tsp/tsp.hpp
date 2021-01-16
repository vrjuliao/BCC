#ifndef HEM_TSP_INTERFACE_HPP
#define HEM_TSP_INTERFACE_HPP

#include <vector>
#include <utility>
#include <functional>

struct Node {
  long double x;
  long double y;
  bool visited;
};

class TSP {
protected:
  std::vector<Node> mAdj_list;

public:
  TSP(const std::vector<std::pair<long double, long double>> &points);
  ~TSP();
  
  virtual int cost(std::function<int(Node, Node)> distance) = 0;
};
  

#endif