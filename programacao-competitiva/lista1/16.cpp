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
    unordered_set<string> sset;
    string s;
    while(cin >> s) sset.insert(s);
    cout << sset.size() << endl;
	return 0;
}
