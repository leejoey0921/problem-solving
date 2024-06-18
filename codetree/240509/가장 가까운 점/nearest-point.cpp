#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    priority_queue<tuple<int, int, int>> pq; // <-distance, -x, -y>

    for (int i; i < n; i++) {
        int x, y; cin >> x >> y;

        int distance = abs(x) + abs(y);
        pq.push({ -distance, -x, -y});
    }
    for (int i; i < m; i++) {
        auto [distance, x, y] = pq.top();
        pq.pop();
        x -= 2; y -= 2;
        distance = abs(x) + abs(y);
        pq.push({-distance, x, y});
    }

    auto [distance, x, y] = pq.top();
    cout << -x << " " << -y;

    return 0;
}

int distance(int x, int y) {
    return abs(x) + abs(y);
}