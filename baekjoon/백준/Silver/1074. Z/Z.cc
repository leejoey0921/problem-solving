#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n, r, c; cin >> n >> r >> c;
    int ans = 0;
    for (int i = pow(2, n-1); i >= 1; i >>= 1) {
        int rq = r / i; int cq = c / i;
        ans += (i*i) * (2*rq + cq);
        r = r % i; c = c % i;
    }
    cout << ans;

    return 0;
}


