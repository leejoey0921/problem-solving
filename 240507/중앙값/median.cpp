#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int t; cin >> t;

    for (int i; i < t; i++) {
        priority_queue<int> lo, hi;
        int m; cin >> m;
        int init; cin >> init;
        lo.push(init); cout << init << " ";
        for (int j=1; j < m; j++) {
            int x; cin >> x;
            if (x > lo.top()) {
                hi.push(-x);
            } else {
                lo.push(x);
            }
            while (lo.size() < hi.size() || lo.size() > (hi.size()+1)) {
                if (lo.size() < hi.size()) {
                    int move = -hi.top();
                    hi.pop();
                    lo.push(move);
                } else {
                    int move = -lo.top();
                    lo.pop();
                    hi.push(move);
                }
            }
            if (j % 2 == 0) {
                cout << lo.top() << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}