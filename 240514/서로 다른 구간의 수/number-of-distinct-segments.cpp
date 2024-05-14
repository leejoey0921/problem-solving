#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n; cin >> n;
    map<int, int> m;

    for (int i; i < n; i++) {
        int l, r; cin >> l >> r;
        m[l]++;
        m[r]--;
    }

    int count = 0;
    int ans = 0;
    
    for (auto [x, c] : m) {
        if (count == 1 && c == -1) {
            ans += 1;
        }
        count += c;
    }

    cout << ans;

    return 0;
}