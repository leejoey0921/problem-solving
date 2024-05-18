#include <bits/stdc++.h>
using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n; cin >> n;
    int grid[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int l = 0; int r = 1e6;
    int ans = 1e6;

    while (l <= r) {
        int mid = (l + r) / 2;

        int max_cnt = 0;
        bool visited[n][n]; fill_n(&visited[0][0], n*n, false);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j]) continue;
                
                int cnt = 1;
                queue<pair<int, int>> q;
                visited[i][j] = true;
                q.push({ i, j });

                while (!q.empty()) {
                    auto [x, y] = q.front(); q.pop();
                    for (int d = 0; d < 4; d++) {
                        int next_x = x + dx[d]; int next_y = y + dy[d];
                        if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= n || visited[next_x][next_y]) continue;
                        if (abs(grid[x][y] - grid[next_x][next_y]) <= mid) {
                            q.push({ next_x, next_y });
                            visited[next_x][next_y] = true;
                            cnt++;
                        }
                    }
                }
                max_cnt = max(max_cnt, cnt);
            }
        }

        if (max_cnt * 2 >= n*n) {
            r = mid - 1;
            ans = min(ans, mid);
        } else {
            l = mid + 1;
        }
    }

    cout << ans;

    return 0;
}