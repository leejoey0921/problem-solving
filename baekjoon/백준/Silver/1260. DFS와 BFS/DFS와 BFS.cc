#include<bits/stdc++.h>
using namespace std;

set<int> dfs_visited;
set<int> bfs_visited;

void dfs(set<int> graph[], int cur) {
    cout << cur << " ";
    dfs_visited.insert(cur);
    set<int> adjacent = graph[cur];
    for (int v : adjacent) {
        if (dfs_visited.find(v) == dfs_visited.end()) {
            dfs(graph, v);
        }
    }
}

void bfs(set<int> graph[], int start) {
    queue<int> q;
    bfs_visited.insert(start);
    q.push(start);
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        cout << cur << " ";
        for (int next : graph[cur]) {
            if (bfs_visited.find(next) == bfs_visited.end()) {
                q.push(next);
                bfs_visited.insert(next);
            }
        }
    }
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n, m, v; cin >> n >> m >> v;
    set<int> graph[n+1];

    for (int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;
        graph[s].insert(e);
        graph[e].insert(s);
    }

    dfs(graph, v);
    cout << "\n";

    bfs(graph, v);

    return 0;
}