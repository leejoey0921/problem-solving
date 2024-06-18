#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    set<string> unseen;
    vector<string> ans;
    for (int i = 0; i < n; i++) {
        string name; cin >> name;
        unseen.insert(name);
    }
    for (int i = 0; i < m; i++) {
        string name; cin >> name;
        if (unseen.find(name) != unseen.end()) ans.push_back(name);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (string name : ans) cout << name << "\n";

    return 0;
}
