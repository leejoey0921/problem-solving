#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n, m; cin >> n >> m;
    set<int> s;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        s.insert(x);
    }

    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        auto q = s.lower_bound(x);
        int ans = -1;

        if (q != s.end()) {
            ans = *q;
        }

        cout << ans << "\n";
    }

    return 0;
}