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

    for (auto it = V.begin(); it != V.end(); it++) {
        cout << *it;
    }

    return 0;
}