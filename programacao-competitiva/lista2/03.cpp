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

unordered_map<string, int> size_index = {
    {"XS", 0}, {"S",1}  , {"M", 2},
    {"L", 3} , {"XL", 4}, {"XXL", 5}
};

bool solve (vector<pair<string, string>> &sizes, vector<int> &qtt, int index) {
    if(index >= sizes.size()) return true;
    int fsize = size_index[sizes[index].f], ssize= size_index[sizes[index].s];
    if(qtt[fsize] > 0){
        --qtt[fsize];
        if(!solve(sizes, qtt, index+1)){
            ++qtt[fsize];
            if(qtt[ssize] <= 0) return false;
            --qtt[ssize];
            if(!solve(sizes, qtt, index+1)) {
                ++qtt[ssize];
                return false;
            }
            return true;
        }
        return true;
    } else if(qtt[ssize] > 0){
        --qtt[ssize];
        if(!solve(sizes, qtt, index+1)) {
            ++qtt[ssize];
            return false;
        }
        return true;
    } 
    return false;
}

int main (void) {_

    int rounds, tshit, volunt;
    vector<int> qtt(6, 0);
    cin >> rounds;
    while(rounds--){
        cin >> tshit >> volunt;
        for(int i=0; i<6; ++i) qtt[i] = tshit/6;
        vector<pair<string, string>> sizes(volunt);
        for(int i=0; i<volunt; ++i) cin >> sizes[i].f >> sizes[i].s;
        if(solve(sizes, qtt, 0)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

	return 0;
}
