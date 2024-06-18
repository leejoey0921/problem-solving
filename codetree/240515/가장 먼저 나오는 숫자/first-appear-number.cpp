#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n, m; cin >> n >> m;

    int a[n];

    for (int i; i < n; i++) {
        cin >> a[i];
    }

    while (m--) {
        int q; cin >> q;
        int l = 0; int r = n-1;
        int ans = n;

        while (l <= r) {
            int m = (l + r) / 2;
            if (a[m] == q) {
                ans = min(ans, m);
                r = m - 1;
            } else if (a[m] > q) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        if (ans == n) {
            ans = -1;
        } else {
            ans++;
        }
        cout << ans << "\n";
    }

    return 0;
}