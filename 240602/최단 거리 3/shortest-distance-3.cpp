#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;

    vector<pii> graph[n+1];
    int dist[n+1];
    fill_n(dist, n+1, 1e9);

    for (int i; i < m; i++) {
        int s, e, w; cin >> s >> e >> w;
        graph[s].push_back({w, e});
        graph[e].push_back({w, s});
    }

    int a, b; cin >> a >> b;
    priority_queue<pii> pq;
    pq.push({0, a});

    while(!pq.empty()) {
        auto [w, v] = pq.top();
        pq.pop();
        w = -w;

        if (dist[v] != 1e9) continue;
        dist[v] = w;

        for (auto [nxt_w, nxt_v] : graph[v]) {
            pq.push({-w - nxt_w, nxt_v});
        }
    }

    cout << dist[b];

    return 0;
}