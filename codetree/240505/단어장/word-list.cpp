#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    map<string, int> m;

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        m[s]++;
    }

    for (auto [word, count] : m) {
        cout << word << " " << count << "\n";
    }
    return 0;
}