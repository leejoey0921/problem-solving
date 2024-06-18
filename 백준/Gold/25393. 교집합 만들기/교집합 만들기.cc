// https://www.acmicpc.net/problem/25393
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    int n; cin >> n;
    unordered_map<int, set<int> > m;

    for (int i = 0; i < n; i++) {
        int s, e; cin >> s >> e;
        m[s].insert(e);
        m[e].insert(s);
    }

    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int s, e; cin >> s >> e;
        int q_e;
        if (m[s].lower_bound(e) != m[s].end()) {
            q_e = *m[s].lower_bound(e);
        } else {
            cout << "-1\n";
            continue;
        }
        if (q_e == e) {
            cout << "1\n";
            continue;
        }
        if (m[e].upper_bound(s) != m[e].begin()) {
            cout << "2\n";
            continue;
        } else {
            cout << "-1\n";
        }
    }
    return 0;
}
