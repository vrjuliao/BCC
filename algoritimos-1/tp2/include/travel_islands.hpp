#ifndef TP2_TRAVEL_ISLANDS
#define TP2_TRAVEL_ISLANDS

#include <vector>
#include <algorithm>
#include <iostream>
#include <utility>

struct Island{
    int mPrice;
    int mScore;
    double mCostBenefit;
};

class TravelIslands{
private:
    std::vector<Island*> mIslands;
    static bool comparator(Island* less, Island* greatter);
public:
    TravelIslands(int islands_qtt);
    void add_island(int index, int price, int score);
    std::pair<int, int> get_better_by_greedy(int max_cost);
    void get_beter_by_dinamyc_programming();
    ~TravelIslands();
};
#endif