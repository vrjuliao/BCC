#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios::sync_with_stdio(false);cin.tie(0);

using namespace std;

typedef long long int ll;
typedef pair<ll,ll> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 1e5 + 10;

void solve (vector<ii> &data, int total, int castle) {
    vector<vector<ll>> ks = vector<vector<ll>>(data.size()+1, vector<ll>(total+1, 0));
    for(int proj=1; proj<=data.size(); ++proj){
        for(int weight=1; weight <= total; ++weight){
            if(weight < data[proj-1].s) {
                ks[proj][weight] = ks[proj-1][weight];
            } else {
                ks[proj][weight] = max(ks[proj-1][weight],
                                      ks[proj-1][weight-data[proj-1].s]+data[proj-1].f);
            }
            
            // cout << ks[proj][weight] << '\t';
        }
        // cout << endl;
    }
    if(ks[data.size()][total] >= castle){
        cout << "Missao completada com sucesso" << endl;
    } else {
        cout << "Falha na missao" << endl;
    }
    // cout << '\t' << ks[data.size()][total] << ": " << castle << endl << endl;
}

int main (void) {_
    int rounds;
    cin >> rounds;
    while(rounds--) {
        ll proj, weight, destruction;
        cin >> proj;
        vector<ii> data(proj, {0,0});
        for(int i=0; i<proj; ++i){
            cin >> destruction >> weight;
            data[i] = make_pair(destruction, weight);
        }
        ll total, castle;
        cin >> total >> castle;
        solve(data, total, castle);
    }
	return 0;
}
