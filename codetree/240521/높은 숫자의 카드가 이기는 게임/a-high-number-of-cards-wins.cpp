#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<int> B;
    set<int> A;
    for (int i = 1; i <= 2*n; i++) {
        A.insert(i);
    }
    int ans = 0;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        B.push_back(x);
        A.erase(x);
    }

    for (int x : B) {
        auto q = A.upper_bound(x);
        if (q != A.end()) {
            ans++;
            A.erase(q);
        }
    }

    cout << ans;

    return 0;
}