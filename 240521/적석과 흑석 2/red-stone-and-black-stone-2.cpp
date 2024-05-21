#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    set<int> Red;
    vector<pii> Black;

    int c, n; cin >> c >> n;

    for (int i = 0; i < c; i++) {
        int x; cin >> x;
        Red.insert(x);
    }

    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        Black.push_back({a, b});
    }

    sort(Black.begin(), Black.end());

    int ans = 0;
    for (auto [s, e] : Black) {
        auto q = Red.lower_bound(s);
        if (q != Red.end() && *q <= e) {
            ans++;
            Red.erase(q);
        }
    }
    cout << ans;

    return 0;
}