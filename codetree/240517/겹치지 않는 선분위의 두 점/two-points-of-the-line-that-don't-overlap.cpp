#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    ll n, m; cin >> n >> m;

    pair<ll, ll> lines[m];
    for (int i = 0; i < m; i++) {
        ll s, e; cin >> s >> e;
        lines[i] = { s, e };
    }
    sort(lines, lines + m);

    ll l = 0; ll r = 1e18;

    ll ans = 0;

    while (l <= r) {
        ll mid = (l + r) / 2;
    
        ll cnt = 0;
        ll pos = -1e18;
        for (auto [s, e] : lines) {
            ll real_s = max(s, pos + mid);
            if (real_s <= e) {
                ll inc = (e - real_s) / mid;
                cnt += 1 + inc;
                pos = real_s + inc * mid;
            }
        }

        if (cnt >= n) { // mid <= ans
            l = mid + 1;
            ans = max(ans, mid);
        } else {
            r = mid - 1;
        }
    }

    cout << ans;

    return 0;
}