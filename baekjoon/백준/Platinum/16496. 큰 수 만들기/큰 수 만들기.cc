#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n; cin >> n;

    vector<string> V;

    for (int i = 0; i < n; i++) {
        string x; cin >> x;
        V.push_back(x);
    }

    sort(V.begin(), V.end(), [&](string s1, string s2) {
        return s2 + s1 < s1 + s2;
    });

    string ans = "";
    for (auto & it : V) ans += it;

    bool leadZero = true;
    for (int i = 0; i < ans.length(); i++) {
        if (ans[i] != '0') leadZero = false;
        if (!leadZero || i == ans.length()-1) cout << ans[i];
    }
    return 0;
}