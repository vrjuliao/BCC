#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios::sync_with_stdio(false);cin.tie(0);

using namespace std;

typedef long long int ll;
typedef pair<int,int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 1e3+10;
int dp[MAX][MAX];

int solve(vector<int> &odd_even){
    int n = odd_even.size();
    for(int i=0; i<n; ++i) for(int j=0; j+i<n; ++j) {
        if(!i) dp[j][j] = 0;

        if(i&1) {
            dp[j][i+j] = max(dp[j+1][i+j] + odd_even[j], dp[j][(i+j)-1] + odd_even[i+j]);
        } else {
            dp[j][i+j] = min(dp[j+1][i+j], dp[j][(i+j)-1]);
        }
    }
    return dp[0][n-1];

}
void clear_dp(int n){
    for(int i=0; i<=n; ++i) for(int j=0; j<=n; ++j)
        dp[i][j] = 0;
}

int main(void) {_
    int n;
    cin >> n;
    while(n){
        int nn = n*2;
        vector<int> input(nn);
        for(int i=0; i<nn; ++i){
            int num;
            cin >> num;
            input[i] = !(num&1);
        }
        clear_dp(nn);
        cout << solve(input) << endl;
        cin >> n;
    }
    return 0;
}
