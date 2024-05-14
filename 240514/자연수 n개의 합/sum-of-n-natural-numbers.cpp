#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int s; cin >> s;
    int l = 0; int r = s;
    int ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        int sum = mid * (mid + 1) / 2;
        if (sum == s) {
            ans = mid;
            break;
        } else if (sum < s) {
            ans = max(ans, mid);
            l = mid + 1;
        } else if (sum) {
            r = mid - 1;
        }
    }
    
    cout << ans;
    
    return 0;
}