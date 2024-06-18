#include <bits/stdc++.h>
using namespace std;

#define MAX 128

int cnt[2] = {0, 0};
int grid[MAX][MAX];

void countPartitions(int n, int x, int y) {
    int color = grid[x][y];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[x+i][y+j] != color) {
                countPartitions(n/2, x, y);
                countPartitions(n/2, x + n/2, y);
                countPartitions(n/2, x, y + n/2);
                countPartitions(n/2, x + n/2, y + n/2);
                return;
            }
        }
    }
    cnt[color]++;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    countPartitions(n, 0, 0);
    cout << cnt[0] << "\n" << cnt[1];

    return 0;
}

