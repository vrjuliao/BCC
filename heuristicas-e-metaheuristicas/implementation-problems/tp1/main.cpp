#include <iostream>
#include <string>
#include <utility>
#include <cmath>

#include "utils/tsplib_parser.hpp"
#include "tsp/tsp.hpp"

int euclidian_distance(const Node &n1, const Node &n2){
  long double xd = n1.x - n2.x;
  long double yd= n1.y - n2.y;
  return std::round( std::sqrt( xd*xd + yd*yd));
}

int pseudo_euclidian_distance(const Node &n1, const Node &n2){
  long double xd= n1.x - n2.x;
  long double yd= n1.y - n2.y;
  long double rij= sqrt( (xd*xd + yd*yd)/10.0 );
  int tij= std::round(rij);

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
  std::cout << parser.get_name() << std::endl;

  std::vector<std::pair<long double, long double>> list = parser.get_points();
  for(int i=0; i<list.size(); i++){
    std::cout << list[i].first << " " << list[i].second << std::endl; 
  }

  return 0;
}