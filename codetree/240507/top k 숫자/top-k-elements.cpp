#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    
    int n, k; cin >> n >> k;

    set<int> s;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        s.insert(-x);
    }
    auto it = s.begin();
    for (int i = 0; i < k; i++) {
        cout << -(*(it++)) << " ";
    }

    return 0;
}