#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    set<pair<int, int>> coords;

    int n, m; cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        coords.insert({x, y});
    }

    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        pair<int, int> ans = {-1, -1};

        auto q = coords.lower_bound({x, y});
        if (q != coords.end()) {
            ans = *q;
        }
        cout << ans.first << " " << ans.second << "\n";
    }

    return 0;
}