#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    ll s; cin >> s;
    ll l = 0; ll r = 1e10;
    ll ans = 0;
    while (l <= r) {
        ll mid = (l + r) / 2;
        ll sum = mid * (mid + 1) / 2;
        if (sum == s) {
            ans = mid;
            break;
        } else if (sum < s) {
            ans = max(ans, mid);
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    
    cout << ans;
    
    return 0;
}