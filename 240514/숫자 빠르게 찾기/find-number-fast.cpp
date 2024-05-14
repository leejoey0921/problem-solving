#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n, m; cin >> n >> m;
    int a[n];

    for (int i; i < n; i++) {
        cin >> a[i];
    }

    for (int i; i < m; i++) {
        int t; cin >> t;

        int l = 0;
        int r = n-1;
        int ans = -1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (a[m] == t) {
                ans = m + 1;
                break;
            } else if (a[m] < t) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}