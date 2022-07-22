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

ll seg[4*MAX];
int trilha[MAX];

ll build(int p, int l, int r) {
    if (l == r) {
        ll pos = 1;
        pos = pos << trilha[l];
        return seg[p] = pos;
    }
    int m = (l+r)/2;
    return seg[p] = build(2*p, l, m) | build(2*p+1, m+1, r);
}

ll query(int a, int b, int p, int l, int r) {
    if (a <= l and r <= b) return seg[p];
    if (b < l or r < a) return 0;
    int m = (l+r)/2;
    return query(a, b, 2*p, l, m) | query(a, b, 2*p+1, m+1, r);
}


ll update(int i, int x, int p, int l, int r) {
    if(i<l || r<i) return seg[p];
    if (l == r) {
        ll pos = 1;
        pos = pos << x;
        return seg[p] = pos;
    }
    int m = (l+r)/2;
    return seg[p] = update(i, x, 2*p, l, m) |
        update(i, x, 2*p+1, m+1, r);
}

ll solve(int l, int r, int n){
    ll monsters_exitence = query(l, r, 1, 0, n-1);
    ll count = 0;
    ll long_one = 1;
    for(int i=0; i<52; ++i){
        monsters_exitence = monsters_exitence >> 1;
        count += monsters_exitence & long_one;
    }
    return count;
}

int main (void) {_
    int n, q, m;
    cin >> n >> q >> m;
    
    for(int i=0; i<n; ++i) {
        cin >> trilha[i];
    }

    build(1, 0, n-1);

    for(int i=0; i<q; ++i){
        int op, l, r;
        cin >> op >> l >> r;
        if(op == 2) update(l-1, r, 1, 0, n-1);
        else cout << solve(l-1, r-1, n) << endl;
    }

	return 0;
}
