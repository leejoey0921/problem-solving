#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n, m; cin >> n >> m;

    ll points[n];

    for (int i; i < n; i++) {
        cin >> points[i];
    }
    sort(points, points + n);

    // 물건 간의 최소 간격으로 이분탐색
    int l = 0; int r = 1e9;

    int ans;
    while (l < r) {
        int mid = (l + r) / 2;

        ll start = points[0];
        int count = 1;
        for (auto p : points) {
            if (p - start >= mid) {
                count++;
                start = p;
            }
        }
        // cout << l << " " << r << " " << mid << " " << count << " " << endl;

        if (count >= m) { // mid <= ans
            l = mid;
            ans = max(ans, mid);
        } else { // mid > ans
            r = mid - 1;
        }
    }

    cout << ans;
    
    return 0;
}