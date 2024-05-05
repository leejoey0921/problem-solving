#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n; cin >> n;
    map<int, string> m;

    for (int i = 0; i < n; i++) {
        string cmd; cin >> cmd;

        if(cmd == "add") {
            int k; cin >> k; string v; cin >> v;
            m[k] = v;
        } else if (cmd == "remove") {
            int k; cin >> k;
            if (m.find(k) != m.end()) {
                m.erase(k);
            }
        } else if (cmd == "find") {
            int k; cin >> k;
            string v = "None";
            auto q = m.find(k);
            if (q != m.end()) {
                v = (*q).second;
            }
            cout << v << "\n";
        } else if (cmd == "print_list") {
            if (m.empty()) {
                cout << "None\n";
            } else {
                for (auto [k, v] : m) {
                    cout << v << " ";
                }
                cout << "\n";
            }
        }
    }
    return 0;
}