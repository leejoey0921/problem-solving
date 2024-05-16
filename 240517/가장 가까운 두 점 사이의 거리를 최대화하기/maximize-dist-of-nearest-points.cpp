#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<pair<int, int>> lines;
    for (int i = 0; i < n; i++) {
        int s, e; cin >> s >> e;
        lines.push_back({ s, e });
    }
    sort(lines.begin(), lines.end());

    int l = 0; int r = 1e9;
    int ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;

        bool possible = true;
        int pos = -1e9;
        for (auto [s, e] : lines) {
            int real_s = max(pos + mid, s);
            if (real_s <= e) {
                pos = real_s;
            } else {
                possible = false;
                break;
            }
        }

        if (possible) {
            l = mid + 1;
            ans = max(mid, ans);
        } else {
            r = mid - 1;
        }
    }
    cout << ans;

    return 0;
}