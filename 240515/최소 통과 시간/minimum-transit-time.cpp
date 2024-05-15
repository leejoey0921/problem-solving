#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    ll n, m; cin >> n >> m;

    ll times[m];

    ll max_time = 0;
    for (int i; i < m; i++) {
        ll t; cin >> t;
        times[i] = t;
        max_time = max(max_time, t);
    }


    ll l = 0; ll r = max_time * (n/m + 1);
    ll ans = r;

    while (l <= r) {
        ll mid = (l + r) / 2;
        ll passed = 0;
        for (ll t : times) {
            passed += mid / t;
        }
        if (passed >= n) {
            ans = min(mid, ans);
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans;
    
    return 0;
}