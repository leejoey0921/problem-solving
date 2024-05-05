#include <bits/stdc++.h>
using namespace std;

int n, k;
unordered_map<int, int> freq;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> n >> k;

    int ans = 0;

    for(int i = 0; i < n; i++) {
        int it; cin >> it;
        freq[it]++;
    }


    for (auto i = freq.begin(); i != freq.end(); i++) {
        for (auto j = next(i); j != freq.end(); j++) {
            int k1, v1, k2, v2;
            k1 = (*i).first; k2 = (*j).first; v1 = (*i).second; v2 = (*j).second;

            int diff = k - k1 - k2;

            cout << ans << "\n";
            cout << k1 << " " << k2 << " " << diff << "\n";
            if (diff == k1) {
                ans += v1 * (v1-1) / 2 * v2;
            } else if (diff == k2) {
                ans += v2 * (v2-1) / 2 * v1;
            } else if (freq[diff] > 0 && freq.find(diff) != freq.end()) {
                ans += v1 * v2 * freq[diff];
            }
        }
    }

    cout << ans;

    return 0;
}