#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n, m, x; cin >> n >> m >> x;
    vector<pii> g[n+1], rev_g[n+1];
    int dist[n+1], rev_dist[n+1];
    fill_n(dist, n+1, 1e9);
    fill_n(rev_dist, n+1, 1e9);

    for (int i; i < m; i++) {
        int s, e, w; cin >> s >> e >> w;
        g[s].push_back({e, w});
        rev_g[e].push_back({s, w});
    }

    priority_queue<pii> pq, rev_pq;
    pq.push({0, x});
    rev_pq.push({0, x});
    while (!pq.empty()) {
        auto [w, v] = pq.top();
        pq.pop();
        w = -w;

        if (dist[v] != 1e9) continue;
        dist[v] = w;

        for (auto [nxt_v, nxt_w] : g[v]) {
            pq.push({-w - nxt_w, nxt_v});
        }
    }
    while (!rev_pq.empty()) {
        auto [w, v] = rev_pq.top();
        rev_pq.pop();
        w = -w;

        if (rev_dist[v] != 1e9) continue;
        rev_dist[v] = w;
        for (auto [nxt_v, nxt_w] : rev_g[v]) {
            rev_pq.push({-w - nxt_w, nxt_v});
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (i == x) continue;
        if (dist[i] == 1e9 || rev_dist[i] == 1e9) continue;
        if (dist[i] + rev_dist[i] > ans) ans = dist[i] + rev_dist[i];
    }

    cout << ans;
    return 0;
}