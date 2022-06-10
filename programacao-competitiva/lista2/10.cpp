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

void solve (const vector<int> &cols) {
    vector<int> rtl(cols.size(), 1);
    vector<int> ltr(cols.size(), 1);

    for(int i=1; i<cols.size(); ++i){
        if(ltr[i-1]<cols[i]) ltr[i] = ltr[i-1]+1;
        else ltr[i] = cols[i];
    }

    for(int i=cols.size()-2; i>=0; --i){
        if(rtl[i+1] < cols[i]) rtl[i] = rtl[i+1]+1;
        else rtl[i] = cols[i];
    }

    int answer = 1;
    for(int i=1; i<cols.size()-1; ++i){
        int current_iso = min(ltr[i-1]+1, min(rtl[i+1]+1, cols[i]));
        answer = max(answer, current_iso);
    }
    cout << answer << endl;
}

int main (void) {_
    int size;
    cin >> size;
    vector<int> cols(size,1);
    for(int i=0; i<size; ++i)
        cin >> cols[i];
    solve(cols);
    return 0;
}
