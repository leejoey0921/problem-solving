#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    map<int, int> m;

    int n; cin >> n;

    for (int i = 1; i <= n; i++) {
        int it; cin >> it;
        if (m.find(it) == m.end()) {
            m[it] = i;
        }
    }

    for (auto [x, p] : m) {
        cout << x << " " << p << "\n";
    }

    return 0;
}