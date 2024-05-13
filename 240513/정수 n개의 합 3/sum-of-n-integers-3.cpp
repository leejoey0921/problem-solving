#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n, k; cin >> n >> k;

    int s[n+1][n+1] = {};
    int arr[n+1][n+1] = {};

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> s[i][j];
        }
    }

    // for (int i = 1; i <= k; i++) {
    //     for (int j = 1; j <= k; j++) {
    //         s[i][j] = arr[i][j] +
    //             s[i - 1][j] +
    //             s[i][j - 1] -
    //             s[i - 1][j - 1];
    //     }
    // }

    // 각 행 별로 누적합을 계산
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            s[i][j] += s[i][j-1];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            s[i][j] += s[i-1][j];
        }
    }

    int ans = -1e8;
    for (int i = k; i < n; i++) {
        for (int j = k; j < n; j++) {
            ans = max(ans, s[i][j] - s[i-k][j] - s[i][j-k] + s[i-k][j-k]);
        }
    }

    cout << ans;

    return 0;
}