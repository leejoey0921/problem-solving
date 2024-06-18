#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

typedef pair<int, int> pii;

int grid[MAX][MAX];

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> m >> n;

    queue<pii> q;
    int unripeCnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x; cin >> x;
            grid[i][j] = x;
            if (x == 1) q.push({i, j});
            else if (x == 0) unripeCnt++;
        }
    }

    if (unripeCnt == 0) {
        cout << 0;
        return 0;
    }

    int ripenCnt = 0;
    int ans = 0;
    int done = false;
    while (!done && !q.empty()) {
        queue<pii> nextQ;
        while(!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            pii next[4] = {{x+1, y}, {x-1, y}, {x, y+1}, {x, y-1}};
            for (auto [nx, ny] : next) {
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 0) {
                    grid[nx][ny] = 1;
                    nextQ.push({nx, ny});
                    ripenCnt++;
                }
            }
        }
        if (ripenCnt == unripeCnt) done = true;
        ans++;
        q = nextQ;
    }

    if (done) {
        cout << ans;
    } else {
        cout << -1;
    }


    return 0;
}
