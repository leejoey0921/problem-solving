#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    ll n, m; cin >> n >> m;

    ll points[n];

    for (ll i; i < n; i++) {
        cin >> points[i];
    }
    sort(points, points + n);

    // 물건 간의 최소 간격으로 이분탐색
    ll l = 0; ll r = 1e9;

    ll ans = 0;
    while (l <= r) {
        ll mid = (l + r) / 2;

        ll start = points[0];
        ll count = 1;
        for (auto p : points) {
            if (p - start >= mid) {
                count++;
                start = p;
            }
        }
        // cout << l << " " << r << " " << mid << " " << count << " " << endl;

        if (count >= m) { // mid <= ans
            ans = max(ans, mid);
            // if (l == r - 1 && l == mid) break;
            l = mid + 1;
        } else { // mid > ans
            r = mid - 1;
        }
    }

    cout << ans;
    
    return 0;
}