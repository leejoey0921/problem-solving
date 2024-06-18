#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n; cin >> n;
    set<pair<int, int>> times; // (y, x)

    for (int i = 0; i < n; i++) {
        int s, e; cin >> s >> e;
        times.insert({e, s});
    }

    int cur_e = -1;
    int ans = 0;
    for (auto it : times) {
        int s = it.second;
        int e = it.first;
        if (s >= cur_e) {
            ans++;
            cur_e = e;
        }
    }
    cout << ans;
    return 0;
}