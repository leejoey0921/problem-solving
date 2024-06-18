#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int x, y; cin >> x >> y;
    if (x == y) {
        cout << 0;
        return 0;
    }

    set<int> visited; visited.insert(x);
    vector<int> q; q.push_back(x);
    int ans = 0;

    bool done = false;
    while (!done) {
        ans++;
        vector<int> next_q;
        for (int cur : q) {
//            cout << cur << " ";
            int next[3] = {cur+1, cur-1, cur*2};
            for (int n : next) {
                if (n < 0 || n > 1e5) continue;
                if (visited.find(n) != visited.end()) continue;
                if (n == y) {
                    done = true;
                    break;
                }
                visited.insert(n);
                next_q.push_back(n);
            }
            if (done) break;
//            cout << endl;
        }
        q = next_q;
    }

    cout << ans;

    return 0;
}
