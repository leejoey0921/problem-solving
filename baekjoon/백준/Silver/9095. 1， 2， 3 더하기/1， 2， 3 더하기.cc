#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int cnts[11] = { 0, 1, 2, 4 };
    for (int i = 4; i <= 10; i++) {
        cnts[i] = cnts[i-3] + cnts[i-2] + cnts[i-1];
    }

    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        int q; cin >> q;
        cout << cnts[q] << "\n";
    }

    return 0;
}
