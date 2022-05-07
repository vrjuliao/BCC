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


int main (void) {_
    int n = 0;
    while(cin >> n){
        vector<ll> tape(n, 0);
        string ss = "";
        for (int i=0; i<n; ++i){
            cin >> tape[i];
            ss+=to_string(tape[i]);
        }
        int m = 0;
        cin >> m;
        string s = "";
        for(int i=0; i<m; ++i){
            ll a = 0;
            cin >> a;
            s += to_string(a);
        }
        char answer = 'N';
        if(m == 1){
            int sm = 0;
            for(int i=0; i<n; ++i){
                sm += tape[i];
            }
            if(s == to_string(sm)) answer = 'S';
        }
        else if(ss == s) answer = 'S';
        else{
            for (int i=0; i<n; ++i){
                ss = "";
                for (int j = n-1; ~j; --j){
                    if ((i-j-1) >= 0 && (i+j) < n) ss += to_string((tape[i-j-1] + tape[i+j]));
                    else if (i-j-1 < 0 && i+j < n) ss += to_string(tape[i+j]);
                    else if (i-j-1 >= 0 && i+j >= n) ss += to_string(tape[i-j-1]);
                }
                if (ss == s){
                    answer = 'S';
                    break;
                }
            }
        }
        cout << answer << endl;
    }
    return 0;
}