#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n, k; cin >> n >> k;

    map<int, int> candies;
    set<int> positions;

    for (int i = 0; i < n; i++) {
        int cnt, pos; cin >> cnt >> pos;
        positions.insert(pos);
        candies[pos] += cnt;
    }

    int cnt = 0;
    int beg_pos = *positions.begin();
    for (auto it = positions.begin(); (*it <= beg_pos + 2*k) && (it != positions.end()); it++) {
        cnt += candies[*it];
    }
    
    auto l = positions.begin();
    auto r = positions.upper_bound(beg_pos+2*k);


    int ans = cnt;
    while (r != positions.end()) {
        cnt += candies[*r];
        int cur_r_pos = *r;
        while(*l < cur_r_pos - 2*k) {
            cnt -= candies[*l];
            l++;
        }
        ans = max(ans, cnt);
        r++;
    }

    cout << ans;

    return 0;
}