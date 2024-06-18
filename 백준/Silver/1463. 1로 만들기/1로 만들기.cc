#include <bits/stdc++.h>
using namespace std;


int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int x; cin >> x;

    set<int> visited = {x};
    vector<int> nums = {x};

    int ans = 0;

    while (true) {
        bool done = false;
        vector<int> next_v;
        for (int n : nums) {
            if (n == 1) done = true;

            if (n % 2 == 0) {
                int next = n / 2;
                if (visited.find(next) == visited.end()) {
                    next_v.push_back(next);
                    visited.insert(next);
                }
            }
            if (n % 3 == 0) {
                int next = n / 3;
                if (visited.find(next) == visited.end()) {
                    next_v.push_back(next);
                    visited.insert(next);
                }
            }
            int next = n - 1;
            if (visited.find(next) == visited.end()) {
                next_v.push_back(next);
                visited.insert(next);
            }
        }
        nums = next_v;
        if (done) break;
        ans++;
    }
    cout << ans;

    return 0;
};