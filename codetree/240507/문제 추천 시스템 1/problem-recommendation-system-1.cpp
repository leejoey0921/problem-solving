#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n; cin >> n;

    set<pair<int, int>> problems; // <difficulty, number>

    for (int i = 0; i < n; i++) {
        int n, d; cin >> n >> d;
        problems.insert({d, n});
    }

    int m; cin >> m;
    for(int i = 0; i < m; i++) {
        string cmd; cin >> cmd;
        if (cmd == "rc") {
            int x; cin >> x;
            if (x == 1) {
                cout << (*problems.rbegin()).second << "\n";
            } else if (x == -1) {
                cout << (*problems.begin()).second << "\n";
            }
        } else if (cmd == "ad") {
            int n, d; cin >> n >> d;
            problems.insert({d, n});
        } else if (cmd == "sv") {
            int n, d; cin >> n >> d;
            problems.erase({d, n});
        }
    }


    return 0;
}