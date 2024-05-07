#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;

    set<int> s;

    for (int i = 0; i < m; i++) {
        s.insert(i+1);
    }

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        s.erase(x);
        cout << *s.rbegin() << "\n";
    }

    return 0;
}