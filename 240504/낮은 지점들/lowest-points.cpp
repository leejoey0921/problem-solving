#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    unordered_map<int, int> m;
    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        if (m.find(x) == m.end() || m[x] > y) {
            m[x] = y;
        }
    }

    int ans = 0;
    for (auto &[x, y] : m) {
        ans += y;
    }

    cout << ans;

    return 0;
}