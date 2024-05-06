#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    unordered_set<int> s;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        s.insert(a);
    }

    int m; cin >> m;
    for (int i = 0; i < m; i++) {
        int b; cin >> b;
        cout << ((s.find(b) != s.end()) ? "1" : "0") << "\n";
    }

    return 0;
}