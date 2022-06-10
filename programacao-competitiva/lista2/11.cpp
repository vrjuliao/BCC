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
int dp[MAX][4*MAX];

int solve(const vector<ii> &spell, int demogorgon_hp, int spell_index, int val) {
    if (spell_index == spell.size()) {
        if (val >= demogorgon_hp) return 0;
        else return INF;
    }

    int &answer = dp[spell_index][val];
    if (answer != -1) return answer;

    answer = min(
        solve(spell, demogorgon_hp, spell_index+1, val),
        solve(spell, demogorgon_hp, spell_index+1, val + spell[spell_index].f) + spell[spell_index].s
    );
    
    return dp[spell_index][val];
}

void clear_dp(){
    for(int i=0; i<MAX; ++i){
        for(int j=0; j<2*MAX; ++j){
            dp[i][j] = -1;
        }
    }
}

int main(void) {_
    int n, p;

    while(cin >> n) {
        cin >> p;
        vector<ii> spell(n);
        for(int i=0; i<n; ++i) cin >> spell[i].f >> spell[i].s;
        clear_dp();
        int answer = solve(spell, p, 0, 0);
        if (answer != INF) cout << answer << endl;
        else cout << -1 << endl;
    }

    return 0;
}