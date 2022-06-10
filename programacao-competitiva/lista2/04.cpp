#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios::sync_with_stdio(false);cin.tie(0);

using namespace std;

typedef long long int ll;
typedef pair<int,int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 1e5 + 10;

int calc(ii p1, ii p2, vector<vector<int>> &dp) {
    p1.f++, p1.s++;
    return dp[p1.f][p1.s] - dp[p1.f][p2.s] - dp[p2.f][p1.s]+ dp[p2.f][p2.s];
}

void solve(vector<vector<char>> &input, int n, int m, int x) {
    vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] + (input[i-1][j-1]=='.');
        }
    }

    int answer = n*m;
    for(int i=0;i <n; i++) {
        for(int j=0; j<m; j++) {
            for(int k=0; k<=j; k++) {
                if(calc({i, j}, {0, k}, dp) < x) break;
                int l = 0, r = i;
                while(l<r){
                    int mm = (l+r+1)/2;
                    if(calc({i, j}, {mm, k}, dp) >= x) l = mm;
                    else r = mm-1;
                }
                answer = min(answer, (i-l+1)*(j-k+1));
            }
        }
    }
    cout << answer << endl;
}

int main(void) {_
    int n, m, x;
    while(true){
        cin >> n >> m >> x;
        if(!n) break;
        vector<vector<char>> input(n, vector<char>(m));
        for(int i=0;i <n; i++) {
            for(int j=0; j<m; j++) {
                cin >> input[i][j];
            }
        }
        solve(input, n, m, x);
    }
    return 0;
}