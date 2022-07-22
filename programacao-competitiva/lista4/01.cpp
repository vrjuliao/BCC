#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios::sync_with_stdio(false);cin.tie(0);

using namespace std;

typedef long long int ll;
typedef pair<int,int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 1e3 + 10;

ll X[MAX], Y[MAX];
ll dp[MAX][MAX];

ll pow_2(ll v) { return v*v; }

int main(void ) {_
    int n;
    cin >> n;
    while(n) {
        for(int i = 0; i < n; ++i) cin >> X[i] >> Y[i];
        ll sum = 0;
        for(int i = 0; i < n; ++i) {
        	int aux = 0;
            for(int j = 0; j < n; ++j) dp[i][aux++] = pow_2(X[i] - X[j]) + pow_2(Y[i] - Y[j]);
                
            sort(dp[i], dp[i] + aux);
            ll last = -1L;
            int cnt = 0;
            
            for(int j = 0; j < aux; ++j) {
                if (dp[i][j] != last) {
                    sum += (cnt * (cnt - 1)) / 2;
                    cnt = 0;
                }
                last = dp[i][j];
                ++cnt;
            }
            sum += (cnt * (cnt - 1)) / 2;
        }

        cout << sum << endl;
        cin >> n;
    }
    return 0;
}