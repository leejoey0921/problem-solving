#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, k; cin >> n >> k;
    ll points[n];
    for (int i = 0; i < n; i++) {
        cin >> points[i];
    }
    sort(points, points+n);

    ll l = 0; ll r = 1e9;
    ll ans = 1e9;

    while (l <= r) {
        ll mid = (l + r) / 2;
        ll cur = points[0];
        int bombs = 1;

        for (int i = 1; i < n; i++) {
            if (points[i] - cur <= 2*mid) {
                continue;
            }
            bombs++;
            cur = points[i];
        }

        if (bombs <= k) {
            r = mid - 1;
            ans = min(ans, mid);
        } else {
            l = mid + 1;
        }
    }
    cout << ans;


    return 0;
}