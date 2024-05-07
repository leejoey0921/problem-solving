#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;

    set<int> nums, diffs;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;

        for (auto y : nums) {
            diffs.insert(abs(x - y));
        }

        nums.insert(x);
    }

    auto ans = diffs.lower_bound(m);

    if (ans == diffs.end()) {
        cout << -1;
    } else {
        cout << *ans;
    }
    return 0;
}