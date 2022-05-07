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

void solve (void) {

}
struct cycle {
    int size;
    unordered_set<int> nodes;
};
typedef vector<deque<pair<int, int>>> gr;



void dfs(gr &graph, int node, vector<bool> &visited, deque<int> &path, vector<cycle> &result){
    for(const auto &next: graph[node]){
        if(visited[next] && result.back() != next){
            // compute cycle using reverse order of the path deque
            // insert such cycle in result
        }
    }
}

vector<cycle> precompute_cycles(gr &graph){
    vector<bool> visited(graph.size(), false);
    vector<cycle> result();
    for(int i=0; i<graph.size(); ++i){
        if(!visited[i]){
            deque<int> path = {i};
            visited[i] = true;
            dfs(graph, i, visited, path, result);
        }
    }
}


int main (void) {_
    int nodes, edges;
    while(cin >> nodes){
        cin >> edges;
        vector<deque<pair<int, int>>> graph(n, deque<pair<int, int>>());

        int to, from, weight;
        for (int i=0; i<n; ++i){
            cin >> to >> from >> weight;
            graph[to-1].push_back({from-1, weight});
            graph[from-1].push_back({to-1, weight});
        }

        // compute cycles
        auto cycles = precompute_cycles(graph);

        int queries, start, worm_size;
        cin >> queries;

        while(queries--){
            cin >> start >> worm_size;
            vector<int> shortest_paths = dijkstra(start-1, weight, graph);

            int min_path_size = INT_MAX;
            for(auto cl: cycles){
                if(cl.size >= worm_size && min_path_size > cl.size){
                    if(shortest_paths[*cl.nodes.begin()] == INT_MAX) continue;
                    for(int node: cl.nodes){
                        int current_min = cl.size + (2*shortest_paths[node]);
                        min_path_size = (min_path_size, current_min);
                    }
                }
            }
            min_path_size = min_path_size == INT_MAX ? -1 : min_path_size;
            cout << min_path_size << endl;
        }

    }


	return 0;
}
