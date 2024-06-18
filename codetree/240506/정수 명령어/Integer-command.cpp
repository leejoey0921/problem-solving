#include<bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        set<int> s;
        int m; cin >> m;
        for (int j = 0; j < m; j++) {
            string cmd; cin >> cmd;
            int x; cin >> x;
            if (cmd == "I") {
                s.insert(x);
            } else if (cmd == "D" && !s.empty()) {
                if (x == -1) {
                    s.erase(s.begin());
                } else if (x == 1) {
                    s.erase(--s.end());
                }
            }
        }
        if (!s.empty()) {
            cout << *s.rbegin() << " " << *s.begin() << "\n";
        } else {
            cout << "EMPTY\n";
        }
    }
    

    return 0;
}