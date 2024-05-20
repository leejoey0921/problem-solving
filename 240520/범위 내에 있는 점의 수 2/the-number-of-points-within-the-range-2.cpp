#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, q; cin >> n >> q;
    int size = 1e6 + 2; // -1 <= k <= 1e6
    int acc[size] = {};
    bool pnt[size] = {};

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        acc[x+2] = 1;
        pnt[x+2] = true;
    }

    for (int i = 0; i <= size-1; i++) {
        acc[i] += acc[i-1];
    }

    for (int i; i < q; i++) {
        int lo, hi; cin >> lo >> hi;
        int include_lo = pnt[lo+2] ? 1 : 0;

        cout << acc[hi+2] - acc[lo+2] + include_lo << endl;
    }

    return 0;
}