#include <bits/stdc++.h>
using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int m, n; cin >> m >> n;

    int grid[m][n];
    set<pair<int, int>> colored;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int is_colored; cin >> is_colored;
            if (is_colored == 1) colored.insert({ i, j });
        }
    }

    int l = 0; int r = 1e9;
    int ans = 1e9;
    while (l <= r) {
        int mid = (l + r) / 2;

        set<pair<int, int>> this_colored; 
        for (auto coord : colored) {
            this_colored.insert(coord);
        }
        queue<pair<int, int>> q;
        bool visited[m][n]; fill_n(&visited[0][0], m * n, false);
        auto begin = this_colored.begin();
        q.push(*begin);
        visited[(*begin).first][(*begin).second] = true;
        this_colored.erase(begin);
        
        while (!q.empty()) {
            auto [as, df] = q.back();

            auto [x, y] = q.front(); q.pop();
            for (int d = 0; d < 4; d++) {
                int next_x = x + dx[d]; int next_y = y + dy[d];
                if (next_x >= 0 && next_x < m && next_y >= 0 && next_y < n && !visited[next_x][next_y]) {
                    if (abs(grid[next_x][next_y] - grid[x][y]) <= mid) {
                        q.push({ next_x, next_y });
                        visited[next_x][next_y] = true;
                        auto find = this_colored.find({ next_x, next_y });
                        if (find != this_colored.end()) {
                            this_colored.erase(find);
                        }
                    }
                }
            }
            if (this_colored.empty()) break;
        }

        if (this_colored.empty()) {
            r = mid - 1;
            ans = min(ans, mid);
        } else {
            l = mid + 1;
        }
    }
    cout << ans;


    return 0;
}