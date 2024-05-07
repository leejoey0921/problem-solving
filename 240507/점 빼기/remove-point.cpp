#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n, m; cin >> n >> m;

    set<pair<int, int>> coords;

    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        coords.insert({x, y});
    }


    for (int i = 0; i < m; i++) {
        int q; cin >> q;
        pair<int, int> answer = {-1, -1};

        auto result = coords.lower_bound({q, 0});        
        if (result != coords.end()) {
            answer = *result;
            coords.erase(result);
        }
        cout << answer.first << " " << answer.second << "\n";
    }
    return 0;
}