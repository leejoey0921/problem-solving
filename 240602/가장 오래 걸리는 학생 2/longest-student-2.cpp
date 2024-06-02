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
        int s, e, w;
        cin >> s >> e >> w;
        graph[e].push_back({s, w});
    }
    

    priority_queue<pii> pq;
    pq.push({0, n});

    while(!pq.empty()) {
        auto [w, v] = pq.top();
        w = -w;
        pq.pop();
        
        if (dist[v] != 1e9) continue;
        dist[v] = w;

        for (auto [nxt_v, nxt_w] : graph[v]) {
            pq.push({-w - nxt_w, nxt_v});
        }
    }

    int ans = 0;
    for (int d : dist) {
        if (d != 1e9 && ans < d) ans = d;
    }
    cout << ans;

    return 0;
}