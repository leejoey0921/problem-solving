#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    map<int, int> m;
    int n; cin >> n;

    for (int i; i < n; i++) {
        int l, r; cin >> l >> r;
        m[l]++;
        m[r]--;
    }

    int count = 0;
    int ans = 0;
    for (auto [x, c] : m) {
        count += c;
        ans = max(ans, count);
    }
    cout << ans;
    return 0;
}