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
    ll n ;
    cin >> n;
    unordered_set<ll> numbers;
    for(ll i=2; (i*i)<=n; ++i){
        while(!(n%i)){
            numbers.insert(i);
            n /= i;
        }
    }
    if(n > 1) numbers.insert(n);
    ll size = numbers.size();
    cout << pow(2,size)-size-1 << endl;
    return 0;
}
