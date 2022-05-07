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

struct Edge {
    int from;
    int to;
    int cost;
};

struct UnionFind {
    int *connected, *rank;
    int n;

    UnionFind(int n) {
        this->n = n;
        connected = new int[n+1];
        rank = new int[n+1];

        for(int i=0; i<=n; i++) {
        rank[i] = 0;
        connected[i] = i;
        }
    }

    int find(int u) {
        if (u != connected[u]) {
        connected[u] = find(connected[u]);
        }
        return connected[u];
    }

    void merge(int x, int y) {
        x = find(x);
        y = find(y);

        if (rank[x] > rank[y]) connected[y] = x;
        else connected[x] = y;

        if (rank[x] == rank[y]) rank[y] = rank[y] + 1;
    }
};

struct Comparator {
    bool operator()(Edge &a, Edge &b) {
        return a.cost < b.cost;
    }
};

int main(void) {_
    int n;
    cin >> n;

    vector<Edge> project(n);
    int numberOfVertices = 0;

    for (int i=0; i<n; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;

        if (from > numberOfVertices) numberOfVertices = from;
        if (to > numberOfVertices) numberOfVertices = to;
        project[i] = Edge{from, to, cost};
    }

    sort(project.begin(), project.end(), Comparator());
    UnionFind min_u_find(numberOfVertices);

    int resultMin = 0;
    for (int i=0; i<project.size(); i++) {
        int firstSet = min_u_find.find(project[i].from);
        int secondSet = min_u_find.find(project[i].to);

        if (firstSet != secondSet) {
        resultMin += project[i].cost;
        min_u_find.merge(firstSet, secondSet);
        }
    }

    
    for (int i=0; i<project.size(); i++) {
        project[i].cost = 0 - project[i].cost;
    }

    sort(project.begin(), project.end(), Comparator());
    UnionFind max_u_find(numberOfVertices);

    int resultMax = 0;
    for (int i=0; i<project.size(); i++) {
        int firstSet = max_u_find.find(project[i].from);
        int secondSet = max_u_find.find(project[i].to);

        if (firstSet != secondSet) {
        resultMax += project[i].cost;
        max_u_find.merge(firstSet, secondSet);
        }
    }

    resultMax = 0-resultMax;

    cout << resultMax << endl;
    cout << resultMin << endl;

    return 0;
}