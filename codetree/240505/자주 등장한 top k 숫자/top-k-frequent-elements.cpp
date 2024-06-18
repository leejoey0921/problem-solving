#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n, k; cin >> n >> k;
    set<pair<int, int>> s;
    unordered_map<int, int> idx;

    for (int i = 0; i < n; i++) {
        int cur; cin >> cur;
        if (idx.find(cur) != idx.end()) {
            s.erase({-idx[cur], -cur});
        }
        s.insert({-(++idx[cur]), -cur});
    }
    auto it = s.begin();
    for (int i = 0; i < k; i++) {
        cout << -((*it++).second) << " ";
    }

    return 0;
}