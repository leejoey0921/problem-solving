#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n; cin >> n;

    priority_queue<int> pq;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        pq.push(-x);
    }
    int ans = 0;
    while (pq.size() > 1) {
        int t1 = pq.top(); pq.pop();
        int t2 = pq.top(); pq.pop();
        pq.push(t1 + t2);
        ans -= (t1 + t2);
    }
    cout << ans;

    return 0;
}