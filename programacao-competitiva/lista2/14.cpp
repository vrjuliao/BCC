#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios::sync_with_stdio(false);cin.tie(0);

using namespace std;

typedef long long int ll;
typedef pair<int,int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 1e4+10;
bool dp[MAX][12];


bool solve(int index, int diff, vector<int> &v) {
    if(diff < 0 || diff > 10) return false;
    if(index == v.size()) return true;
    if(dp[index][diff]) return true;

    dp[index][diff] = solve(index+1, diff-v[index], v) || solve(index+1, diff+v[index], v);
    return dp[index][diff];
}

void clear_dp(int n){
    for(int i=0;i <=n; i++) {
        for(int j=0; j<=10; j++){
            dp[i][j] = false;
        }
    }
}

int main(void) {_
    int rounds;
    cin >> rounds;
    while(rounds--){
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i=0; i<n; ++i) cin >> v[i];
        clear_dp(n);
        if(solve(0, 5, v)) cout << "Feliz Natal!" << endl;
        else cout << "Ho Ho Ho!" << endl;
    }
    return 0;
}