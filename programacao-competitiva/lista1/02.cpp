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
    ll casted_val;
    ll bucks[] = {10000, 5000, 2000, 1000, 500, 200};
    ll cents[] = {50, 25, 10, 5, 1};

    string fp_in;
    cin >> fp_in;
    int dot_pos = fp_in.find('.');
    string without_point = fp_in.substr(0, dot_pos) + fp_in.substr(dot_pos+1);

    ll in = atol(without_point.c_str());

    cout << "NOTAS:" <<endl;
    for(auto buck: bucks){
        ll div = in/buck;
        ll used_bucks = div*buck;
        cout << div <<" nota(s) de R$ " << buck/100 <<".00" << endl;
        in -= used_bucks;
    }
    cout <<"MOEDAS:" <<endl;
    ll div = in/100;
    ll used_bucks = div*100;
    cout << div <<" moeda(s) de R$ 1.00" << endl;
    in -= used_bucks;
    for(auto cent: cents){
        ll div = in/cent;
        ll used_bucks = div*cent;
        string output = " moeda(s) de R$ 0.";
        if(cent < 10) {
            output+= "0";
        } 
        cout << div << output << cent << endl;
        in -= used_bucks;
    }

	return 0;
}