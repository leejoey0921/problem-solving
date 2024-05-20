#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, d; cin >> n >> d;
    set<pair<int, int>> coords;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        coords.insert({x, y});
    }

    set<pair<int, int>> cur_y;

    auto l = coords.begin(); auto r = coords.begin();
    while (r != coords.end()) {
        cur_y.insert({(*r).second, (*r).first});
        if ((*cur_y.rbegin()).first - (*cur_y.begin()).first >= d) break;
        r++;
    }
    if (r == coords.end()) {
        cout << -1;
        return 0;
    }

    int ans = (*r).first - (*l).first;

    while(l != r && r != coords.end()) {
        cur_y.erase({(*l).second, (*l).first});
        l++;
        while (r != coords.end()) {
            cur_y.insert({(*r).second, (*r).first});
            if ((*cur_y.rbegin()).first - (*cur_y.begin()).first >= d) break;
            r++;
        }
        if (r == coords.end()) break;

        if ((*cur_y.rbegin()).first - (*cur_y.begin()).first >= d) {
            ans = min(ans, (*r).first - (*l).first);
        }
    }

    cout << ans;

    return 0;
}