#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;

    set<int> nums, diffs;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        nums.insert(x);
    }

    long long ans = 1e10 + 1;

    for (int x : nums) {
        auto y = nums.lower_bound(x + m);
        if (y != nums.end()) {
            ans = min(ans, (long long) (*y - x));
        }
    }

    if (ans == 1e10 + 1) {
        cout << -1;
    } else {
        cout << ans;
    }
    return 0;
}