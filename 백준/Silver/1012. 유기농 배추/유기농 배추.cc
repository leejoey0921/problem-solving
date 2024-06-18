#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

struct pair_hash {
    inline std::size_t operator()(const std::pair<int,int> & v) const {
        return v.first*31+v.second;
    }
};

void countGroups() {
    int n, m, k; cin >> n >> m >> k;

    unordered_set<pii, pair_hash> unvisited;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    for (int i = 0; i < k; i++) {
        int x, y; cin >> x >> y;
        unvisited.insert({x, y});
    }

    int ans = 0;
    while (!unvisited.empty()) {
        queue<pii> q;
        q.push(*unvisited.begin());
        unvisited.erase(unvisited.begin());
        while (!q.empty()) {
            pii cur = q.front(); q.pop();
            for (int i = 0; i < 4; i++) {
                pii next = {cur.first + dx[i], cur.second + dy[i]};
                if (unvisited.find(next) != unvisited.end()) {
                    q.push(next);
                    unvisited.erase(unvisited.find(next));
                }
            }
        }
        ans ++;
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int t; cin >> t;

    while (t > 0) {
        countGroups();
        t--;
    }
    return 0;
}
