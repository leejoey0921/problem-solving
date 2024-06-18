#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

typedef pair<int, int> pii;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    int grid[n][m];
    int ans[n][m];
    fill_n(&ans[0][0], n*m, -1);

    queue<pii> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x; cin >> x;
            grid[i][j] = x;
            if (x == 2) {
                q.push({i, j});
                ans[i][j] = 0;
            } else if (x == 0) {
                ans[i][j] = 0;
            }
        }
    }

    int cnt = 1;

    while (!q.empty()) {
        queue<pii> nQ;
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            pii next[4] = {{x+1, y}, {x-1, y}, {x, y+1}, {x, y-1}};
            for (auto [nx, ny] : next) {
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1) {
                    nQ.push({nx, ny});
                    ans[nx][ny] = cnt;
                    grid[nx][ny] = 3;
                }
            }
        }
        q = nQ;
        cnt++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}
