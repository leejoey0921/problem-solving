#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n; cin >> n;

    int l = 0; int r = 1e9;

    while (l <= r) {
        int mid = (l + r) / 2;
        int cnt = mid - (mid/3) - (mid/5) + (mid/15);
        if (cnt == n) {
            cout << mid;
            break;
        } else if (cnt > n) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return 0;
}