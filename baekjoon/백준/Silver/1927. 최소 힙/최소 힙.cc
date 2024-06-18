#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    priority_queue<int> pq;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int q; cin >> q;
        if (q == 0) {
            if (pq.empty()) {
                cout << "0\n";
            } else {
                cout << -pq.top() << "\n";
                pq.pop();
            }
        } else {
            pq.push(-q);
        }
    }

    return 0;
}
