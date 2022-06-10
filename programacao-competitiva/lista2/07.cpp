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
char dp [110][110][110];

void clear_dp(int n){
    for(int i=0; i<=n; ++i) for(int j=0; j<=n; ++j) for(int k=0; k<=n; ++k)
        dp[i][j][k] = -1;
}


const vector<vector<int>> mul_aux = {{0,0,1},{0,1,0},{0,1,1},{1,0,0},{1,0,1},{1,1,0},{1,1,1}};
bool rec_solve (const vector<int> &a, const vector<int> &b, const vector<int> &c, int pa, int pb, int pc, int sum) {
    if(sum%3 || pa > a.size() || pb > b.size() || pc > c.size()) return false;
    if(pa == a.size() && pb == b.size() && pc == c.size()) return true;
        
    if(dp[pa][pb][pc] != -1) return dp[pa][pb][pc]==1;
    bool ret = false;
    for(const auto &nmul: mul_aux){
        int new_sum = (a[pa]*nmul[0])
                    + (b[pb]*nmul[1])
                    + (c[pc]*nmul[2]);

        ret |= rec_solve(a,b,c,pa+nmul[0],pb+nmul[1],pc+nmul[2],new_sum);
    }
    dp[pa][pb][pc] = ret;
    return ret;
}

void solve (const vector<int> &a, const vector<int> &b, const vector<int> &c) {
    clear_dp(a.size());
    cout << rec_solve(a, b, c, 0, 0, 0, 0) <<  endl; //" - " << maxa << ' ' << maxb << ' ' << maxc << endl;

}

int main (void) {_
    int n;
    cin >> n;
    while(n){
        vector<int> a(n+1);
        vector<int> b(n+1);
        vector<int> c(n+1);
        for(int i=0; i<n; ++i){
            cin >> a[i] >> b[i] >> c[i];
        }
        solve(a, b, c);

        cin >> n;
    }
	return 0;
}
