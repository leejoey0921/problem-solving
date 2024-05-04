#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    
    string s; cin >> s;
    unordered_map<char, int> count, order;

    for (int i = 0; i < s.length(); i++) {
        count[s[i]]++;
        if (order.find(s[i]) == order.end()) {
            order[s[i]] = i;
        }
    }

    int min_order = 1e5;
    string ans = "None";

    for (auto [c, x] : count) {
        int o = order[c];
        if (x == 1 && o < min_order) {
            min_order = o;
            ans = c;
        }
    }

    cout << ans;

    return 0;
}