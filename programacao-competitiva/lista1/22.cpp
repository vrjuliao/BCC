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

bool checkOff(vector<bool> &theater) {
    for(auto l: theater) {
        if(l) return false;
    }
    return true;
}

int main(void) {_
    
    int switchesQtt, numLam;
    cin >> switchesQtt >> numLam;
    vector<bool> theater(numLam, false);

    int on;
    cin >> on;

    int l;
    while(on--){
        cin >> l;
        theater[l-1] = true;
    }
    vector<vector<int>> switches(switchesQtt, vector<int>());
    for (int i=0; i < switchesQtt; i++){
        int c;
        cin >> c;
        int p;
        for (int j = 0; j < c; j++){
            cin >> p;
            switches[i].push_back(p-1);
        }
    }

    int counter = 0;
    int help = 0;
    
    int iter = 0;
    while(true) {
        for (int i = 0; i < switches.size(); i++) {
            iter++;
            counter++;
            for(auto l:switches[i]) {
                theater[l] = !theater[l];
            }
            if(checkOff(theater)) {
                help = 1;
                break;
            }
        }
        if(help == 1) {
            break;
        }
        if(iter > 100000) {
            help = 2;
            break;
        }   
    }

    if(help == 2){
        cout << -1 << endl;
    } else {
        cout << counter << endl;
    }
    return 0;
}