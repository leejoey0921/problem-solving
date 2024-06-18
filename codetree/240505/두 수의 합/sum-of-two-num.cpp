#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n, k; cin >> n >> k;
    int sum = 0;
    unordered_map<int, int> m;

    for (int i = 0; i < n; i++) {
        int cur; cin >> cur;
        m[cur]++;
    }

    for (auto& it: m) {
        int diff = k - it.first;
        if (diff == it.first) {
            sum += it.second * (it.second - 1) / 2;
        } else if (it.second > 0 && m.find(diff) != m.end()) {
            sum += it.second * m[diff];
            m[diff] = 0;
        }
    }
    cout << sum;

    return 0;
}