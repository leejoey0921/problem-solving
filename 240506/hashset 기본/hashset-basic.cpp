#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    unordered_set<int> s;
    for (int i = 0; i < n; i++) {
        string cmd; cin >> cmd;
        int x; cin >> x;
        if (cmd == "find") {
            string result = (s.find(x) != s.end()) ? "true" : "false";
            cout << result << "\n";
        } else if (cmd == "add") {
            s.insert(x);
        } else if (cmd == "remove") {
            if (s.find(x) != s.end()) {
                s.erase(x);
            }
        }
    }
    // 여기에 코드를 작성해주세요.
    return 0;
}