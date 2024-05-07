#include<bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    set<int> seats;

    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        seats.insert(i);
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        int q; cin >> q;
        auto it = seats.upper_bound(q);
        if (it == seats.begin()) {
            break;
        }
        seats.erase(--it);
        ans++;
    }

    cout << ans;

    return 0;
}