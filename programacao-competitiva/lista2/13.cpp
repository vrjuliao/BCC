#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios::sync_with_stdio(false);cin.tie(0);

using namespace std;

typedef long long int ll;
typedef pair<int,int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAX1 = 1e3 + 10;
const int MAX2 = 1e2 + 10;
double dp[MAX1][MAX2];


double solve (vector<ii> &room, int index, int mana, const int damage) {
    if(index >= room.size()) return .0;
    if(dp[index][mana] >= 0) return dp[index][mana];
    
    double min_time = (static_cast<double>(room[index].f)/damage)
                    + solve(room, index+1, mana, damage);
    
    if(mana > 0) {
        double increased_power = static_cast<double>(room[index].s+damage);
        min_time = min(min_time,
                       (static_cast<double>(room[index].f)/increased_power) 
                            + solve(room, index+1, mana-1, damage)
        );
    }
    dp[index][mana] = min_time;
    return min_time;

}

void clear_dp(int max_room, int max_mana){
    for(int i=0; i<=max_room; ++i) for (int j=0; j<=max_mana; ++j)
        dp[i][j] = -1.;
}

int main (void) {_
    int n, k, v;
    while(cin >> n) {
        cin >> k >> v;
        vector<ii> room(n, {0,0});
        for(int i=0; i<n; ++i) cin >> room[i].f >> room[i].s;
        clear_dp(n, k);
        printf("%.4f\n", solve(room, 0, k, v));
    }

	return 0;
}
