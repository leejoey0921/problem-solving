#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    ll n; cin >> n;

    ll l = 0; ll r = 2e9;
    ll ans = 0;
    while (l <= r) {
        ll mid = (l + r) / 2;
        ll cnt = mid - (mid/3) - (mid/5) + (mid/15);
        if (cnt == n) {
            ans = mid;
            break;
        } else if (cnt > n) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    while ((ans % 3 == 0) || (ans % 5 == 0)) {
        ans--;
    }
    cout << ans;
    return 0;
}