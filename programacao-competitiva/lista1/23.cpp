#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios::sync_with_stdio(false);cin.tie(0);

using namespace std;

typedef long long int ll;
typedef pair<int,int> point;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 1e5 + 10;

double distance (point p1, point p2){
    return hypot(p1.f-p2.f, p1.s-p2.s);
}

struct circle{
    point p;
    int radius;
    int set_index;
};

bool intersection(circle &c1, circle &c2){
    return distance(c1.p, c2.p) <= c1.radius+c2.radius;
}

vector<unordered_set<int>> aggregate_circle_by_intersection(vector<circle> &circles) {
    auto sets = vector<unordered_set<int>>();
    
    for (int i=0; i<circles.size(); ++i){
        for (int j=0; j<circles.size(); ++j){
            if (i == j) continue;
            if (intersection(circles[i],circles[j])){
                if (circles[i].set_index != -1 || circles[j].set_index != -1){
                    if (circles[i].set_index == circles[j].set_index) continue;
                    else if (circles[i].set_index == -1 || circles[j].set_index == -1){
                        int parent=i, child=j;
                        if(circles[i].set_index == -1) {
                            parent = j;
                            child = i;
                        }
                        int idx;
                        idx = circles[parent].set_index;
                        sets[idx].insert(child);
                        circles[child].set_index = idx;
                    } else {
                        int idx1 = circles[i].set_index, idx2 = circles[j].set_index;
                        for(int child: sets[idx2]){
                            sets[idx1].insert(child);
                            circles[child].set_index = idx1;
                        }
                        sets[idx2].clear();
                    }
                } else {
                    int idx = sets.size();
                    circles[i].set_index = idx;
                    circles[j].set_index = idx;
                    sets.push_back(unordered_set<int>({i,j}));
                }
            }
        }
        if (circles[i].set_index == -1){
            sets.push_back(unordered_set<int>({i}));
        }
    }
    return sets;
}


int main(void) {_
    int m, n, s;
    cin >> n >> m >> s;

    vector<circle> circles(s);
    int x, y, r;
    for (int i = 0; i<s; i++){
        cin >> x >> y >> r;
        circles[i] = circle{make_pair(x,y), r, -1};
    }
    vector<unordered_set<int>> circle_sets = aggregate_circle_by_intersection(circles);
    
    for (int i = 0; i < circle_sets.size(); i++) {
        int minX = m+1, maxX = 0, minY = n+1, maxY = 0;
        for(int next: circle_sets[i]) {
            circle caux = circles[next];
            minX = min(minX, caux.p.f-caux.radius);
            maxX = max(maxX, caux.p.f+caux.radius);
            minY = min(minY, caux.p.s-caux.radius);
            maxY = max(maxY, caux.p.s+caux.radius);
        }
        if ((minX <= 0 && (maxX >= n || minY <= 0)) || (maxY >= m && (minY <= 0 || maxX >= n))){
            cout << "N" << endl;
            return 0;
        }
    }
    cout << "S" << endl;
    return 0;
}