#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    unordered_set<int> s;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        s.insert(x);
    }

    int m; cin >> m;
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        int q = (s.find(x) != s.end()) ? 1 : 0;
        cout << q << " ";
    }
    return 0;
}