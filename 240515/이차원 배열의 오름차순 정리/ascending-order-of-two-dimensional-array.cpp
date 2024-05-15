#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    ll n, k; cin >> n >> k;

    ll l = 1; ll r = n * n;
    ll ans = n * n;

    while(l <= r) {
        ll mid = (l + r) / 2;
        ll cnt = 0;
        for (ll i = 1; i <= n; i++) {
            cnt += min(n, mid / i);
        }

        if (cnt >= k) {
            r = mid - 1;
            ans = min(ans, mid);
        } else {
            l = mid + 1;
        }
    }

    cout << ans;

    return 0;
}