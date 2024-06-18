#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    priority_queue<int> pq;

    for (int i; i < n; i++) {
        int x; cin >> x;
        pq.push(x);
    }

    while (pq.size() > 1) {
        int t1 = pq.top(); pq.pop();
        int t2 = pq.top(); pq.pop();
        int diff = abs(t1 - t2);
        if (diff != 0) {
            pq.push(diff);
        }
    }

    if (pq.size() == 1) {
        cout << pq.top();
    } else {
        cout << -1;
    }
    return 0;
}