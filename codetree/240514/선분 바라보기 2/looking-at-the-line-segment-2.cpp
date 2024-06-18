#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n; cin >> n;
    tuple<int, int, int> a[n];
    bool visible[n];

    for (int i; i < n; i++) {
        int y, l, r; cin >> y >> l >> r;
        a[i] = { y, l, r };
    }

    vector<tuple<int, int, int, int>> v;

    for(int i; i < n; i++) {
        int y, l, r;
        tie(y, l, r) = a[i];
        v.push_back(make_tuple(l, +1, i, y)); // 시작점
        v.push_back(make_tuple(r, -1, i, y)); // 끝점
    }
    sort(v.begin(), v.end());

    
    set<pair<int, int>> s;
    for(int i = 0; i < 2 * n; i++) {
        int m, index, y;
        tie(ignore, m, index, y) = v[i];

        if(m == +1) {
            s.insert(make_pair(y, index));
        }

        else {
            s.erase(make_pair(y, index));
        }

        if(s.begin() == s.end())
            continue;

        int target_index = 0;
        tie(ignore, target_index) = *s.begin();
        visible[target_index] = true;
    }

    int ans = 0;
    for(int i = 0; i < n; i++)
        if(visible[i])
            ans++;
    
    cout << ans;


    return 0;
}