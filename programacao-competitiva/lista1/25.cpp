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


bool good_time(vector<ll> &sacos, ll time, ll p, ll r){
    ll total_pipocas = time*r;
    ll pipocas_acc = sacos[0];
    for(size_t i=1; i<sacos.size(); ++i){
        if(pipocas_acc+sacos[i] > total_pipocas){
            --p;
            pipocas_acc = 0;
        }
        pipocas_acc += sacos[i];
        if(sacos[i] > total_pipocas) break;
    }
    return p > 0 && pipocas_acc <= total_pipocas;
}

int main (void) {_
    ll n, players, rate;
    cin >> n >> players >> rate;
    vector<ll> sacos(n, 0);
    ll pipocas=0;
    for(size_t i=0; i<n; ++i){
        cin >> sacos[i];
        pipocas += sacos[i];
    }

    ll maxtime = pipocas/rate + 1;
    ll mintime = maxtime/2;

    while(good_time(sacos, mintime, players, rate)){
        mintime /= 2;
    }

    ll answer = maxtime;
    ll two = 2;
    while(mintime < maxtime){
        ll middletime = (mintime+maxtime)/two;
        if(good_time(sacos, middletime, players, rate)){
            answer = middletime;
            maxtime = middletime-1;
        } else {
            mintime = middletime+1;
        }
    }
    if(good_time(sacos, answer-1, players, rate)) --answer;
    cout << answer << endl;
	return 0;
}
