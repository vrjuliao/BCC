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


ll seg[4*MAX], lazy[4*MAX];
int n, t, k;

void update(int a, int b, int x, int last, int p=1, int l=0, int r=n-1) {
    if (b < l or r < a) return;
    seg[p] = max(last, seg[p])
    if (a <= l and r <= b) {
        seg[p] = seg[p]+t >= x ? x : seg[p];
        return;
    }
    int m = (l+r)/2;
    update(a, b, x, seg[p], 2*p, l, m);
    update(a, b, x, seg[p], 2*p+1, m+1, r);
}

void get_answer(vector<int> &ans, int p=1, int l=0, int r=n-1) {
    if(seg[p]+t > k){
        for(int i=l; i<=r; ++i) ans.push_back(i);
        return;
    } else {
        if(l==r) return;
        int m = (l+r)/2;
        get_answer(ans, 2*p, l, m);
        get_answer(ans, 2*p+1, m+1, r);    
    }
}


int main (void) {_
    while(cin >> n) {
        cin >> k >> t;
        int l, r;
        for(int i=0; i<4*MAX; ++i){
            seg[i] = lazy[i] = 0;
        }

        for(int i=1; i<=k; ++i){
            cin >> l >> r;
            update(l-1, r-1, i, 0);
        }

        vector<int> indexes;
        // for(int i=0; i<n; ++i){
        //     ll last_day = query(i,i);
        //     cout << last_day << ' ';
        //     if(last_day+t >= k) indexes.push_back(i+1);
        // }
        // cout << endl;
        get_answer(indexes);
        cout << indexes.size();
        for(int &idx: indexes) cout << ' ' << idx+1;
        cout << endl;
        // cout << endl;
    }
    
	return 0;
}
