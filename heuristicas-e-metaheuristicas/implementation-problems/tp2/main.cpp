#include <iostream>
#include <string>
#include <utility>
#include <cmath>

#define ATT "ATT"
#define EUC_2D "EUC_2D"

#include "utils/tsplib_parser.hpp"
#include "tsp/tsp.hpp"
#include "tsp/opt2_tsp.hpp"


int euclidian_distance(const Node &n1, const Node &n2){
  long double xd = n1.x - n2.x;
  long double yd = n1.y - n2.y;
  return static_cast<int>(std::round(std::sqrt((xd*xd) + (yd*yd))));
}

int pseudo_euclidian_distance(const Node &n1, const Node &n2){
  long double xd= n1.x - n2.x;
  long double yd= n1.y - n2.y;
  long double rij= sqrt( (xd*xd + yd*yd)/10.0 );
  int tij= static_cast<int>(std::round(rij));

  if(tij<rij)
    return tij+1;
  
  return tij;
}


int main(int argc, const char* argv[]){
  if (argc != 2){
    std::cerr << "A filepath of a TSPLIB instance is required as an execution "
      << "argument" << std::endl;
    return 1;
  }

  TSPLIB_Parser parser = TSPLIB_Parser(std::string(argv[1]));
  std::string type = parser.get_edge_weight_type();
  std::vector<std::pair<long double, long double>> list = parser.get_points();
  Opt2_TSP solver = Opt2_TSP(list);

  if (type == EUC_2D){
    solver.set_distance_function(&euclidian_distance);
  } else if(type == ATT){
    solver.set_distance_function(&pseudo_euclidian_distance);
  } else {
    std::cerr << "Not recognized edges weight type" << std::endl;
    exit(1);
  }
  solver.solve();

  std::cout << solver.cost() << std::endl;

  return 0;
}