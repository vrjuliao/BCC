#ifndef HEM_TSPLIB_PARSER_HPP
#define HEM_TSPLIB_PARSER_HPP

#include <string>
#include <utility>
#include <vector>
#include <fstream>

#define NAME_KW "NAME"
#define EDGE_WEIGHT_TYPE_KW "EDGE_WEIGHT_TYPE"
#define NODE_COORD_SECTION_KW "NODE_COORD_SECTION"
#define DIMENSION_KW "DIMENSION"
#define EOF_KW "EOF"

class TSPLIB_Parser {
private:
  // attributes 
  std::string mName, mEdgeWeightType;
  int mDimension;
  std::vector<std::pair<long double, long double>> mPointsList;

  // methods
  void visit(std::ifstream &instance_file);
  std::pair<std::string, std::string> get_key_and_value(const std::string &line);
  void read_pairs(std::ifstream &instance_file);

public:
  TSPLIB_Parser(std::string filepath);
  std::string get_name();
  std::string get_edge_weight_type();
  std::vector<std::pair<long double, long double>> get_points();
};


#endif