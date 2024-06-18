#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;

    set<int> bounds;
    map<int, int> lengths;
    bounds.insert(-1);
    bounds.insert(n+1);
    lengths[n+1] = 1;

    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        auto it = bounds.lower_bound(x);
        int hi = *it; int lo = *(--it);

        int erased = hi - lo - 1; // (lo+1) ~ (hi-1) -> hi-lo-1
        if (lengths[erased] == 1) {
            lengths.erase(erased);
        } else {
            lengths[erased]--;
        }

        lengths[hi - x - 1]++;
        lengths[x-lo-1]++;
        bounds.insert(x);

        cout << (*(--lengths.end())).first << "\n";
    }

    return 0;
}