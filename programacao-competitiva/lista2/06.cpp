#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios::sync_with_stdio(false);cin.tie(0);

using namespace std;

typedef long long int ll;
typedef pair<int,int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAX = (1<<8) + 8;
int dp[MAX][MAX];

int solve (const vector<int> &rol, const vector<int> &balls) {
    int spaces = rol.size();
    int div_rest;
    int answer = 0-INF;

    for(int i=0; i<spaces; ++i) {
        dp[0][i] = balls[0]*(rol[(i+1)%spaces]+rol[i]);
        for(int j=1; j<spaces; ++j) {
            div_rest = (i+j)%spaces;
            dp[0][div_rest] = max (
                dp[0][(div_rest+spaces-1)%spaces],
                balls[0]*(rol[div_rest] + rol[(div_rest+1)%spaces])
            );
        }

        for(int k=1; k<rol.size(); ++k){
            for(int l=0; l<spaces; ++l) dp[k][l] = 0-INF;
            for(int l=(k<<1); l<spaces-1; ++l) {
                div_rest = (i+l)%spaces;
                dp[k][div_rest] = max (
                    dp[k][(div_rest+spaces-1)%spaces],
                    balls[k]*(rol[div_rest] + rol[(div_rest+1)%spaces]) + dp[k-1][(div_rest+spaces-2)%spaces]
                );
            }
        }

        answer = max(answer, dp[balls.size()-1][(i+spaces-2)%spaces]);
    }

    return answer;
}

int main(void) {_
    int spaces, tballs;
    cin >> spaces;
    while(spaces) {
        cin >> tballs;
        vector<int> rol(spaces);
        for(int i=0; i<spaces; ++i) {
            cin >> rol[i];
        }

        vector<int> balls(tballs);
        for(int i=0; i<tballs; ++i) {
            int ball;
            cin >> ball;
            balls[i] = 0-ball;
        }

        cout << solve(rol, balls) << endl;
        cin >> spaces;
    }

    return 0;
}