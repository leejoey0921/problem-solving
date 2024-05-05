#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    map<string, int> m;

    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        string word; cin >> word;
        m[word]++;
    }

    for (auto [word, count] : m) {
        float ratio = (float) count / (float) n * 100;
        
        cout << fixed << setprecision(4) << word << " " << ratio << "\n";
    }

    return 0;
}