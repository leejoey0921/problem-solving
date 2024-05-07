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

    for (int i; i < m; i++) {
        int q; cin >> q;
        auto ans = s.upper_bound(q);
        if (ans != s.begin()) {
            cout << *(--ans) << "\n";
            s.erase(ans);
        } else {
            cout << "-1\n";
        }
    }

    return 0;
}