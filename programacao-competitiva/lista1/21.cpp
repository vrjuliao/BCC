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
    string crib, input;
    cin >> crib >> input;
    int qtt = 0;
    for(int i=0; i<=crib.size()-input.size(); ++i){
        int inc = 1;
        for(int j=0; j<input.size(); ++j){
            inc &= crib[i+j] != input[j];
            if(!inc) break;
        }
        qtt += inc;
    }
    cout << qtt << endl;
	return 0;
}
