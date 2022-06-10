#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios::sync_with_stdio(false);cin.tie(0);

using namespace std;

typedef long long int ll;
typedef pair<int,int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 55;
// int free_seats[MAX][MAX];
int dp[MAX][MAX];
int solve (vector<vector<ii>> &graph, int node, int players);

int min_by_recursive_iteration(vector<vector<ii>> &graph, int node, int neigh, int players){
    if (players == 0 || graph[node].empty()) return 0;
    if(neigh == graph[node].size()-1) return solve(graph, graph[node][neigh].f, players);
    int answer = INF;
    for(int i=players; i>0; --i){
        int day_incr = i%graph[node][neigh].s == 0 ? 0 : 1;
        int days = (i/graph[node][neigh].s) + day_incr;
        answer = min(answer,
                    days+solve(graph, graph[node][neigh].f, i)+min_by_recursive_iteration(graph, node, neigh+1, i));
    }
    return answer+1;
}


int solve (vector<vector<ii>> &graph, int node, int players) {
    // cout << node << ": " << players;
    if(node == graph.size()) return 1;
    int &answer = dp[node][players];
    if(answer != -1) return answer;
    answer = min_by_recursive_iteration(graph, node, 0, players);
    // cout << ": " << answer << endl;
    return answer;
}

void clear_dp(){
    for(int i=0; i<MAX; ++i) for(int j=0; j<MAX; ++j)
        dp[i][j] = -1;
}

void print_dp(int n) {
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }

}

int main (void) {_

    // nodes = airports
    // edges = available seats
    // players
    int nodes, edges, players;
    cin >> nodes;
    while(nodes){
        cin >> edges >> players;
        vector<vector<ii>> graph(nodes, vector<ii>());
        for(int i=0; i<edges; ++i){
            int from, to, seats;
            cin >> from >> to >> seats;
            graph[from-1].push_back({to-1, seats});
        }
        clear_dp();
        cout << nodes << ": " << edges << ": " << players << endl;;
        cout << solve(graph, 0, players) << endl;
        print_dp(nodes);
        cin >> nodes;
    }
	return 0;
}
