#include "tsp/tabu_tsp.hpp"
// #include <iostream>

Tabu_TSP::Tabu_TSP(const std::vector<std::pair<long double, long double>> &points): Greedy_TSP(points){}

Tabu_TSP::~Tabu_TSP(){}

int Tabu_TSP::cost(){
  return this->path_cost;
}

void Tabu_TSP::solve(){
  int size = mAdj_list.size();
  if(size < 2) return;
  
  
  
  // get the nearest neighbor for each node
  std::vector<NN> nn_list = std::vector<NN>(size);
 
  int current_cost, potential_next_cost;

  current_cost = distance(mAdj_list[0], mAdj_list[1]);
  nn_list[0] = NN{1, current_cost, false};
  for(int j=2; j<size; j++){
    potential_next_cost = distance(mAdj_list[0], mAdj_list[j]);
    if(potential_next_cost < current_cost){
      current_cost = potential_next_cost;
      nn_list[0].cost = current_cost;
      nn_list[0].next = j;
    }
  }
  
  for(int i=1; i<size; i++){
    current_cost = distance(mAdj_list[i], mAdj_list[0]);
    nn_list[i] = NN{0, current_cost, false};
    for(int j=1; j<size; j++){
      if (i==j) continue;
      potential_next_cost = distance(mAdj_list[i], mAdj_list[j]);
      if(potential_next_cost < current_cost){
        current_cost = potential_next_cost;
        nn_list[i].cost = current_cost;
        nn_list[i].next = j;
      }
    }
  }
 
  // tabu search
  int next_solution_cost, cur, nxt;
  this->path = mAdj_list;
  std::vector<Node> next_solution = std::vector<Node>(size);
  int neighbor1, neighbor2;
  this->path_cost = Greedy_TSP::cost();
  
  // std::cout << this->path_cost << std::endl;
  

  for(int i=0; i<size; i++){
    neighbor1 = i;
    neighbor2 = nn_list[neighbor1].next;

    if(nn_list[neighbor1].already_ocurred){
      continue;
    }
    else {
      if(nn_list[neighbor2].next == neighbor1)
        nn_list[neighbor2].already_ocurred = true;
      nn_list[neighbor1].already_ocurred = true;
    }

    // clear the is_visited flag from the mAjd_list
    for(int j=0; j<size; j++)
      mAdj_list[j].visited = false;

    next_solution[0] = mAdj_list[neighbor1];
    mAdj_list[neighbor1].visited = true;

    cur = neighbor2;
    next_solution[1] = mAdj_list[neighbor2];
    mAdj_list[neighbor2].visited = true;
    next_solution_cost = nn_list[neighbor1].cost;

    int best_cost, possible_best_cost;
    for(int j=2; j<size; j++){
      nxt = 0;
      while(mAdj_list[nxt].visited) nxt++;
      best_cost = this->distance(mAdj_list[cur], mAdj_list[nxt]);
      for(int k=0; k<size; k++){
        if(!mAdj_list[k].visited){
          possible_best_cost = this->distance(mAdj_list[cur], mAdj_list[k]);
          if(possible_best_cost < best_cost){
            best_cost = possible_best_cost;
            nxt = k;
          }
        }
      }

      // if the path cur->nxt exists in the nn_list, we need mark it
      if(nn_list[nxt].next == cur)
        nn_list[nxt].already_ocurred = true;
      if(nn_list[cur].next == nxt)
        nn_list[cur].already_ocurred = true;

      cur = nxt;
      next_solution[j] = mAdj_list[cur];
      next_solution_cost += best_cost;
    }
    if(nn_list[cur].next == neighbor1)
      nn_list[cur].already_ocurred = true;
    next_solution_cost += this->distance(mAdj_list[neighbor1], mAdj_list[cur]);

    if(next_solution_cost < this->path_cost){
      this->path_cost =  next_solution_cost;
      this->path = next_solution;
    }
  }
}

