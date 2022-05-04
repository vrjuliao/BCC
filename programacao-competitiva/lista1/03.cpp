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


void bfs(vector<vector<int>> &graph, vector<bool> &visited, int st_node){
    deque<int> bfs_list = {st_node};
    visited[st_node] = true;
    vector<int> to_print = {};
    while(!bfs_list.empty()){
        int node = bfs_list.front();
        bfs_list.pop_front();
        to_print.push_back(node);
        for(int next: graph[node]){
            if(!visited[next]) {
                bfs_list.push_back(next);
                visited[next] = true;
            }
        }
    }
    sort(to_print.begin(), to_print.end());
    for (int node: to_print)
        cout << static_cast<char>(node+'a') << ',';
    cout << endl;
}

void solve (void) {
    int nodes, edges;
    cin >> nodes >> edges;
    vector<vector<int>> graph = vector<vector<int>>(nodes, vector<int>());
    
    char n1, n2;
    for(int i=0; i<edges; ++i){
        cin >> n1 >> n2;
        graph[n1-'a'].push_back(n2-'a');
        graph[n2-'a'].push_back(n1-'a');
    }

    vector<bool> visited = vector<bool>(nodes, false);
    int count = 0;
    for(int i=0; i<nodes; ++i){
        if(!visited[i]) {
            ++count;
            bfs(graph, visited, i);
        }
    }
    cout << count << " connected components" << endl <<endl;

}

int main (void) {_

    int rounds;
    cin >> rounds;
    for(int i=1; i<=rounds; ++i){
        cout << "Case #" << i <<':' <<endl;
        solve();
    }

	return 0;
}