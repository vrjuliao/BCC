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

void solve (void) {

}

int main (void) {_
    string input;
    cin >> input;
    int answer=0;
    int zero = '0';
    for(char c: input){
        int cc = 0-zero+c;
        answer += (cc%3);
    }
    cout << answer%3 << endl;
	return 0;
}
