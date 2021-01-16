#include "utils/tsplib_parser.hpp"
#include <iostream>
#include <sstream>

TSPLIB_Parser::TSPLIB_Parser(std::string filepath){
  mDimension = -1;
  std::ifstream instance(filepath);
  mPointsList = std::vector<std::pair<long double, long double>>();

  if(!instance.is_open()){
    std::cerr << "Unable to open file " << filepath << std::endl;
    exit(1);
  }
  visit(instance);
  instance.close();
}

std::pair<std::string, std::string> TSPLIB_Parser::get_key_and_value(const std::string &line){
  size_t separator = line.find(':', 0);

  if(separator == std::string::npos)
    return std::make_pair(line, "");
  
  std::stringstream aux_stream(line.substr(0, separator));
  std::string keyword, value;

  aux_stream >> keyword;
  aux_stream = std::stringstream(line.substr(separator+1));
  aux_stream >> value;
  return std::make_pair(keyword, value);
}

void TSPLIB_Parser::read_pairs(std::ifstream &instance){
  int index, tsh;
  long double x, y;
  for(index=1; index<=mDimension; index++){
    instance >> tsh >> x >> y;
    mPointsList.push_back(std::make_pair(x, y));
  }
}


void TSPLIB_Parser::visit(std::ifstream &instance){
  std::string line, keyword, value;
  std::pair<std::string, std::string> parsed_line;
  
  while(getline(instance, line)){
    parsed_line = this->get_key_and_value(line);
    if(parsed_line.second == ""){
      if (parsed_line.first == NODE_COORD_SECTION_KW){
        this->read_pairs(instance);
      }
    } else{
      keyword = parsed_line.first;
      value = parsed_line.second;

      if(keyword == NAME_KW)
        mName = value;
      else if(keyword == DIMENSION_KW)
        mDimension = atoi(value.c_str());
      else if(keyword == EDGE_WEIGHT_TYPE_KW)
        mEdgeWeightType = value;
      else if(keyword == EOF_KW)
        return;
    }
  }
}

std::string TSPLIB_Parser::get_name(){
  return mName;
}

std::string TSPLIB_Parser::get_edge_weight_type(){
  return mEdgeWeightType;
}

std::vector<std::pair<long double, long double>> TSPLIB_Parser::get_points(){
  return mPointsList;
}