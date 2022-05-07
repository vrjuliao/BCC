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

const vector<vector<string>> braile = {
{".*", "**", ".."},
{"*.", "..", ".."},
{"*.", "*.", ".."},
{"**", "..", ".."},
{"**", ".*", ".."},
{"*.", ".*", ".."},
{"**", "*.", ".."},
{"**", "**", ".."},
{"*.", "**", ".."},
{".*", "*.", ".."}
};


int main (void) {_
    unordered_map<string, int> braile_to_int;
    for(int i=0; i<10; ++i){
        string s = braile[i][0]+ braile[i][1]+ braile[i][2];
        // cout << s << " -> " << i << endl;
        braile_to_int[s] = i;
    }
    // cout <<endl;

    int next_size;
    cin >> next_size;
    while(next_size){
        char type;
        cin >> type;
        if(type == 'S'){
            string input;
            cin >> input;
            for(int k=0; k<3; ++k){
                for(int i=0; i<input.size(); ++i){
                    // break;
                    cout << braile[input[i]-'0'][k];
                    if(i < input.size()-1) cout << ' ';
                }
                cout << endl;
            }
        } else {
            vector<string> brcode(next_size, "");
            string input;
            for(int k=0; k<3;++k){
                for(int i=0; i<next_size; ++i){
                    cin >> input;
                    brcode[i]+=input;
                }
            }
            for(string code: brcode){
                // cout << code << " " << braile_to_int[code] << endl;;
                cout << braile_to_int[code];
            }
            cout << endl;
            
        }
        cin >> next_size;
    }

	return 0;
}
