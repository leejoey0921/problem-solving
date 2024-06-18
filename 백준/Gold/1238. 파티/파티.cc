#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

vector<pii> graph[1010];
vector<pii> rGraph[1010];
int dist[1010];
int rDist[1010];

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m, x; cin >> n >> m >> x;

    fill_n(dist, n+1, 1e9);
    fill_n( rDist, n+1, 1e9);

    for (int i = 0; i < m; i++) {
        int s, e, w; cin >> s >> e >> w;
        graph[s].push_back({w, e});
        rGraph[e].push_back({w, s});
    }

    priority_queue<pii> pq;
    pq.push({0, x});
    while(!pq.empty()) {
        auto [cw, cv] = pq.top(); pq.pop();
        cw = -cw;
        if (dist[cv] != 1e9) continue;
        dist[cv] = cw;

        for (auto [nw, nv] : graph[cv]) {
            pq.push({-cw - nw, nv});
        }
    }
    pq.push({0, x});
    while(!pq.empty()) {
        auto [cw, cv] = pq.top(); pq.pop();
        cw = -cw;
        if (rDist[cv] != 1e9) continue;
        rDist[cv] = cw;

        for (auto [nw, nv] : rGraph[cv]) {
            pq.push({-cw - nw, nv});
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (i == x) continue;
        if (dist[i] == 1e9 || rDist[i] == 1e9) continue;
        ans = max(ans, dist[i] + rDist[i]);
    }
    cout << ans;

    return 0;
}
