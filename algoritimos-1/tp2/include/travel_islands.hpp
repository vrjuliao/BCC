#ifndef TP2_TRAVEL_ISLANDS
#define TP2_TRAVEL_ISLANDS

#include <vector>
#include <algorithm>
#include <iostream>
#include <utility>

//structure to compute each island that girls want to visit
struct Island{
    int mPrice;
    int mScore;
    double mCostBenefit;
};

class TravelIslands{
private:
    std::vector<Island*> mIslands;
    //comparator used by std::sort()
    static bool comparator(Island* less, Island* greatter);
public:
    // constructor
    // @param islands_qtt: Quantity of islands got on stdin
    TravelIslands(int islands_qtt);

    // create a new island
    // @param index: vector position to add a new island
    // @param price: cost to visit island
    // @param score: score gave by girls for island
    void add_island(int index, int price, int score);

    // get a pair containning the score and
    // quantity of days by maximization score using greedy agorithm
    // @param max_cost: maximize the score considering max_cost
    std::pair<int, int> get_better_by_greedy(int max_cost);

    // get a pair containning the score and
    // quantity of days by maximization score dynamic programming
    // @param max_cost: maximize the score considering max_cost
    std::pair<int, int> get_beter_by_dinamyc_programming(int max_cost);

    //destructor
    ~TravelIslands();
};
#endif