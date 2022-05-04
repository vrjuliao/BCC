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

int twoSum(vector<int> &tabs, int w, int h, int tab_l){
    int wcount = -1;
    int lines = (w*100) / tab_l;
    if(!((w*100) % tab_l)) {
        wcount = 0;
        unordered_map<int, int> twoSumMap;
        for(int i=0; i<tabs.size(); ++i){
            ++twoSumMap[tabs[i]];
        }
        if(twoSumMap.count(h)){
            wcount = min(twoSumMap[h], lines);
            twoSumMap[h] = 0;
            lines-=wcount;
        }
        
        for(int tab: tabs){
            if(!lines) break;
            if(twoSumMap[tab]){
                --twoSumMap[tab];
                if(twoSumMap.count(h-tab) && twoSumMap[h-tab] ){
                    wcount+=2;
                    --lines;
                    --twoSumMap[h-tab];
                } else {
                    ++twoSumMap[tab];
                }
            }
        }
    }
    return !lines ? wcount : -1;

}

int solve (int w, int h, int tab_l, vector<int> &tabs) {
    if(((w*100) % tab_l) && ((h*100)%tab_l))
        return -1;
    
    int minw = twoSum(tabs, w, h, tab_l),
        minh = twoSum(tabs, h, w, tab_l);
    
    if(minw < 0) return minh;
    else if (minh < 0) return minw;
    else return min(minh, minw);
}

int main (void) {_
    int h,w;
    int tab_l, tab_q;
    int  num_tab, x;
    while(cin >> w >> h) {
        if(!w && !h) return 0;
        cin >> tab_l >> tab_q;
        vector<int> tabs(tab_q, 0);
        for (int i=0; i<tab_q; ++i){
            cin >> x;
            tabs[i] = x;
        }
        int answer = solve(w,h,tab_l, tabs);
        if(answer < 0)
            cout << "impossivel" << endl;
        else
            cout << answer << endl;
    }
	return 0;
}