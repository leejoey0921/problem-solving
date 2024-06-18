#include <bits/stdc++.h>
using namespace std;

vector<int> graph[1001];
bool visited[1001] = {};

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n, m; cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int s, e; cin >> s >> e;
        graph[s].push_back(e);
        graph[e].push_back(s);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;
        queue<int> q; q.push(i);
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            for (int next : graph[cur]) {
                if (!visited[next]) {
                    q.push(next);
                    visited[next] = true;
                }
            }
        }
        ans++;
    }
    cout << ans;

    return 0;
}
