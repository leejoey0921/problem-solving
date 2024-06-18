#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    priority_queue<int> pq;

    for (int i; i < n; i++) {
        int x; cin >> x;
        pq.push(x);
    }

    for (int i; i < m; i++) {
        int top = pq.top();
        pq.pop();
        pq.push(top-1);
    }
    cout << pq.top();
    return 0;
}