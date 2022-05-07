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

struct sol {
	int toys;
	int weight;
	int qtt;
	int last_used;
};

void solve (vector<ii> &pkgs) {
	/*for(ii &p: pkgs){ 
		cout << p.first << " " << p.second << endl;
	}
	cout << "===========" <<  endl;*/

	vector<vector<sol>> kps(pkgs.size()+1, vector<sol>(51, sol{0,0,0,-1}));

	for(int i=1; i<=pkgs.size(); ++i){
		for(int j=1; j<51; ++j){

			if(j >= pkgs[i-1].second){
				int idx = j-pkgs[i-1].s;
				const int toys = pkgs[i-1].f+kps[i-1][idx].toys;
				if (toys >= kps[i-1][j].toys){
					kps[i][j] = sol{toys, kps[i-1][idx].weight+pkgs[i-1].s, kps[i-1][idx].qtt+1, i-1};
				} else {
					kps[i][j] = kps[i-1][j];
				}
				// cout << j << ":" << kps[i][j].toys << " ";
			} else {
				kps[i][j] = kps[i-1][j];
			}
			
		}
		// cout << endl;

	}

	cout << kps[pkgs.size()][50].toys << " brinquedos" << endl;
	cout <<  "Peso: " << kps[pkgs.size()][50].weight << " kg" << endl;
	cout << "sobra(m) " << pkgs.size() - kps[pkgs.size()][50].qtt << " pacote(s)" << endl << endl;
}

int main (void) {_
	int rounds;
	cin >> rounds;
	while(rounds--){
		int qtt;
		cin >> qtt;
		vector<pair<int, int>> pkgs(qtt, {0, 0});
		for(int i=0; i<qtt; ++i){
			cin >> pkgs[i].f >> pkgs[i].s;
		}
		solve(pkgs);
	}
	return 0;
}
