#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    ll n, k; cin >> n >> k;

    // x -> x가 몇변째
    // 1 2 3 4
    // 2 4 6 8
    // 3 6 9 12
    // 4 8 12 16
    //  1 2 2 3 3 4 4 4 6 6 8 8 9 12 12 16

    ll l = 0; ll r = 1e10;
    ll ans;

    while(l <= r) {
        ll mid = (l + r) / 2;
        ll cnt = 0;
        for (ll i = 1; i <= n; i++) {
            cnt += min(n, mid / i);
        }

        // cout << l << " " << r << " " << mid << " " << cnt << " " << endl;
        if (cnt == k) {
            ans = mid;
            break;
        } else if (cnt > k) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans;


    return 0;
}