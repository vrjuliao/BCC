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
  std::vector<Node> path;
  std::function<int(Node, Node)> distance;
  bool is_solved;

public:
  TSP(const std::vector<std::pair<long double, long double>> &points);
  ~TSP();
  void set_distance_function(std::function<int(Node, Node)> distance);
  
  virtual int cost() = 0;
  virtual void solve() = 0;
  virtual std::vector<Node> get_route();
};
  

#endif