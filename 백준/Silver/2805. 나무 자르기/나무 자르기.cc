#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> trees;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    ll n, k; cin >> n >> k;
    ll l = 0; ll r = 0;
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        trees.push_back(x);
        r = max(r, x);
    }

    ll ans = 0;
    while (l <= r) {
        ll mid = (l + r)/2;
        ll len = 0;
        for (ll t : trees) {
            len += max(t - mid, (ll) 0);
        }

        if (len >= k) {
            l = mid + 1;
            ans = max(ans, mid);
        } else {
            r = mid - 1;
        }
    }
    cout << ans;

    return 0;
}
