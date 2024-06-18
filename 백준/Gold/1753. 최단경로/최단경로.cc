#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

unordered_map<int, int> g[20202];
int d[20202];

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n, m, x; cin >> n >> m >> x;
    fill_n(d, n+1, 1e9);

    for (int i = 0; i < m; i++) {
        int s, e, w; cin >> s >> e >> w;
        if (g[s].find(e) != g[s].end()) g[s][e] = min(g[s][e], w);
        else g[s][e] = w;
    }

    priority_queue<pii> pq;
    pq.push({0, x});

    while (!pq.empty()) {
        auto [cw, cv] = pq.top();
        pq.pop();
        if (d[cv] != 1e9) continue;
        d[cv] = -cw;
        for (auto [nv, nw] : g[cv]) {
            if (d[nv] != 1e9) continue;
            pq.push({cw - nw, nv});
        }
    }

    for (int i = 1; i <= n; i++) {
        string dist = (d[i] == 1e9) ? "INF" : to_string(d[i]);
        cout << dist << "\n";
    }

    return 0;
}
