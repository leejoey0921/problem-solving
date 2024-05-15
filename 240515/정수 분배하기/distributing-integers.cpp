#include<bits/stdc++.h>
using namespace std;

int groups(int x, vector<int> v) {
    int res = 0;
    for (auto i : v) {
        res += i / x;
    }
    // cout << x << " " << res << "\n"
    return res;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n, m; cin >> n >> m;
    vector<int> v;

    int max_val = 0;
    for (int i; i < n; i++) {
        int x; cin >> x;
        v.push_back(x);

    }

    int l = 0; int r = 1e8;
    int mid = (l + r) / 2;
    
    while (l < r) {
        // cout << r << " " << l << " ";
        mid = (l + r) / 2;
        if (l == r - 1) break;
        if (groups(mid, v) < m) { // mid > answer
            r = mid - 1;
        } else { // mid <= answer
            l = mid;
        }
    }

    cout << mid;

    return 0;
}