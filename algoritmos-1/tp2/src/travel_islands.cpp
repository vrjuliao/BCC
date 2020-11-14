#include "travel_islands.hpp"

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
    island->mCostBenefit = static_cast<double>(score) / static_cast<double>(price);
    mIslands[index] = island;
}

std::pair<int, int> TravelIslands::get_better_by_greedy(int max_cost){
    //sorting mIslands vector by Island.mCostBenefit
    std::sort(mIslands.begin(), mIslands.end(), TravelIslands::comparator);
    int size = mIslands.size();
    int points = 0, days = 0;
    int quocient;
    // fetch all options of Islands from bigger to smaller mCostBenefit
    for(int i=size-1; i >= 0; i--){
        quocient = max_cost/mIslands[i]->mPrice;
        days += quocient;
        points += (quocient*mIslands[i]->mScore);
        max_cost = max_cost%mIslands[i]->mPrice;
    }
    //pair.first -> total score by greddy algorithm
    //pair.secont -> total days computed according the total score
    return std::pair<int, int>(points, days);
}

std::pair<int, int> TravelIslands::get_beter_by_dinamyc_programming(int max_cost){
    // for each pair of matrix M
    // pair.first -> score
    // pair.second -> quantity of days

    int size = mIslands.size();
    std::vector<std::vector<std::pair<int,int>>> M = std::vector<std::vector<std::pair<int,int>>>(size+1);
    
    //create matrix to solve te problem
    for(int i=0; i<=size; i++){
        M[i] = std::vector<std::pair<int,int>>(max_cost+1);
        //set the first column by zero
        M[i][0] = std::pair<int,int>(0,0);
    }
    //set the first line by zero
    for(int i=1; i<=max_cost; i++){
        M[0][i] = std::pair<int,int>(0,0);
    }
    int current_cost;
    int score_including_j, days_inlcuding_j;
    int before_j_including_j;

    // applying knackpack algorithm variation
    // the matrix cell M[i][j] represents the better choise than M[k][h], with k < i and h < j
    for(int i=1; i <= size; i++){
        for(int j=1; j <= max_cost; j++){
            current_cost = j;
            if(mIslands[i-1]->mPrice > current_cost){
                M[i][j] = std::pair<int,int>(M[i-1][j]);
            } else {
                
                before_j_including_j = current_cost - mIslands[i-1]->mPrice;
                score_including_j = M[i-1][before_j_including_j].first + mIslands[i-1]->mScore;
                if(M[i-1][j].first > score_including_j){
                    M[i][j] = std::pair<int,int>(M[i-1][j]);
                } else {
                    days_inlcuding_j = M[i-1][before_j_including_j].second+1;
                    M[i][j] = std::pair<int,int>(score_including_j, days_inlcuding_j);
                }
            }
        }
    }
    return M[size][max_cost];
}

TravelIslands::~TravelIslands(){
    int size = mIslands.size();
    for(int i = 0; i < size; i++) delete mIslands[i];
    mIslands.clear();
}