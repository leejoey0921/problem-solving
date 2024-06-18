#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<int> graph[n+1];
    for (int i = 0; i < m; i++) {
        int s, e; cin >> s >> e;
        graph[s].push_back(e);
        graph[e].push_back(s);
    }

    unordered_set<int> visited; visited.insert(1);
    queue<int> q; q.push(1);

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int next : graph[cur]) {
            if (visited.find(next) != visited.end()) continue;
            q.push(next);
            visited.insert(next);
        }
    }
    cout << visited.size() - 1;

    return 0;
}
