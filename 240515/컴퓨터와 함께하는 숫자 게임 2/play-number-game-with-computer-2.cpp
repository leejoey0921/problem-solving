#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    ll m; cin >> m;
    ll a, b; cin >> a >> b;

    int min_cnt = 2e9; int max_cnt = 0;

    for (ll i = a; i <= b; i++) {
        ll l = 1; ll r = m;
        int cnt = 0;
        while (l <= r) {
            cnt++;
            int mid = (l + r) / 2;
            if (mid == i) {
                min_cnt = min(min_cnt, cnt);
                max_cnt = max(max_cnt, cnt);
                break;
            } else if (mid > i) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
    }

    cout << min_cnt << " " << max_cnt << "\n";

    return 0;
}