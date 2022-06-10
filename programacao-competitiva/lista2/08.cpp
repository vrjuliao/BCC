#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios::sync_with_stdio(false);cin.tie(0);

using namespace std;

typedef long long int ll;
typedef pair<int,int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 1e2 + 10;
ll dp[MAX][MAX][MAX];

ll solve(int p, int at, int tam, const vector<int> &v) {
	if(tam==0) return 1;
	if(p==v.size()-1){
		if(tam!=1) return 0;
		if(at>=v[p]) return 0;
		return 1;
	}
	ll &ret = dp[p][at][tam];
	if(ret!=-1) return ret;
	ret = solve(p+1, at, tam, v);
	if(v[p]>at) ret += solve(p+1,v[p], tam-1, v);
    return ret;
}

int main(void) {_
    int n, k;
	while(true){
		cin >> n >> k;
		if(n==0) break;
		
		vector<int> v(n,0);
		for(int i=0; i<v.size(); ++i)
            cin >> v[i];
		
		vector<int> aux = v;
		sort(aux.begin(), aux.end());
		unordered_map<int, int> mp;
		int ptr = 1;
		for(const auto &num: aux) if(!mp.count(num)) mp[num] = ptr++;
		for(auto &num: v) num = mp[num];
		
		for(int i=0;i <=n; i++){
            for(int j=0; j<=n; j++) {
                for(int l=0; l<=n; l++){
			        dp[i][j][l]=-1;
                }
            }
        }
		cout << solve(0, 0, k, v) << endl;
	}

	return 0;
}
