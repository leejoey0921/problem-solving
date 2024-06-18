#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n; int m;
    cin >> n >> m;

    bool visited[n+1] = {};
    int dist[n+1];
    fill_n(dist, n+1, 1e9);
    dist[1] = 0;

    int graph[n+1][n+1] = {};

    for (int i = 0; i < m; i++) {
        int s, e, w;
        cin >> s >> e >> w;
        graph[s][e] = w;
    }

    for (int i = 1; i <= n; i++) {
        int next = -1;
        for (int j = 1; j <= n; j++) {
            if (!visited[j] && (next == -1 || dist[next] > dist[j])) {
                next = j;
            }
        }
        if (dist[next] == 1e9) break;

        visited[next] = true;

        for (int j = 0; j <= n; j++) {
            if (graph[next][j] == 0) continue;
            dist[j] = min(dist[j], dist[next] + graph[next][j]);
        }
    }

    for(int i = 2; i <= n; i++) {
        int d = (dist[i] == 1e9) ? -1 : dist[i];
        cout << d << "\n";
    }

    return 0;
}