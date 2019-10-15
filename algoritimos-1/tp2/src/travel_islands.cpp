#include "travel_islands.hpp"

/*struct Island{
    int mPrice;
    int mScore;
};*/

bool TravelIslands::comparator(Island* less, Island* greatter){
    return less->mCostBenefit < greatter->mCostBenefit;
}

TravelIslands::TravelIslands(int islands_qtt){
    mIslands = std::vector<Island*>(islands_qtt);
}

void TravelIslands::add_island(int index, int price, int score){
    Island *island = new Island();
    island->mPrice = price;
    island->mScore = score;
    island->mCostBenefit = static_cast<double>(score) / price;
    mIslands[index] = island;
}
std::pair<int, int> TravelIslands::get_better_by_greedy(int max_cost){
    std::sort(mIslands.begin(), mIslands.end(), TravelIslands::comparator);
    int size = mIslands.size();
    int points = 0, days = 0;
    int quocient;
    for(int i=size-1; i >= 0; i--){
        quocient = max_cost/mIslands[i]->mPrice;
        days += quocient;
        points += (quocient*mIslands[i]->mScore);
        max_cost = max_cost%mIslands[i]->mPrice;
    }
    return std::pair<int, int>(points, days);
}

void TravelIslands::get_beter_by_dinamyc_programming(){}

TravelIslands::~TravelIslands(){
    int size = mIslands.size();
    for(int i = 0; i < size; i++) delete mIslands[i];
    mIslands.clear();
}