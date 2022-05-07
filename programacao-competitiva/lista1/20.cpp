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

vector<int> dijkstra(vector<vector<ii>> &graph, int start) {
    vector<int> weights(graph.size(), INT_MAX);
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, start});
    while(!pq.empty()){
        ii node = pq.top();
        pq.pop();
        if(node.f < weights[node.s]){
            weights[node.s] = node.f;
            for(ii next: graph[node.s]){
                if(next.f+node.f < weights[next.s])
                    pq.push({next.f+node.f, next.s});
            }
        }
    }
    return weights;
}

int main (void) {_
    int n, m;
    int to, from, weight;
    cin >> n >> m;
    vector<vector<ii>> graph(n, vector<ii>());
    
    for(int i=0; i<m; ++i){
        cin >> to >> from >> weight;
        graph[to-1].push_back({weight, from-1});
        graph[from-1].push_back({weight, to-1});
    }
    int start;
    cin >> start;
    vector<int> weights = dijkstra(graph, start-1);
    int mmax = *max_element(weights.begin(), weights.end());
    weights[start-1] = mmax;
    int mmin = *min_element(weights.begin(), weights.end());
    cout << mmax - mmin << endl;
}
