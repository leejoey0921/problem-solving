#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    int times[n];
    for (int i = 0; i < n; i++) {
        cin >> times[i];
    }
    sort(times, times + n);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += times[i] * (n-i);
    }
    cout << ans;


    return 0;
}
