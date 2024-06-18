#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    priority_queue<int> pq;
    
    int n; cin >> n;

    for (int i; i < n; i++) {
        string cmd; cin >> cmd;
        if (cmd == "push") {
            int x; cin >> x;
            pq.push(x);
        } else if (cmd == "top") {
            cout << pq.top() << "\n";
        } else if (cmd == "size") {
            cout << pq.size() << "\n";
        } else if (cmd == "pop") {
            cout << pq.top() << "\n";
            pq.pop();
        } else if (cmd == "empty") {
            string out = pq.empty() ? "1\n" : "0\n";
            cout << out;
        }
    }

    return 0;
}