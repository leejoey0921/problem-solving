// https://www.acmicpc.net/problem/30960
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    int diff[n-1];
    for (int i = 0; i < n-1; i++) {
        diff[i] = arr[i+1] - arr[i];
    }
    if (n == 3) {
        cout << diff[0] + diff[1];
        return 0;
    }

    int m = 0;
    ll l_sum = 0; ll r_sum = 0;
    for(int i = 3; i < n-1; i += 2) {
        r_sum += diff[i];
    }
    ll ans = l_sum + r_sum + diff[m] + diff[m+1];
    while (m < n-3) {
        l_sum += diff[m];
        m += 2;
        r_sum -= diff[m+1];
        ans = min(ans, l_sum + r_sum + diff[m] + diff[m+1]);
    }
    cout << ans;

    return 0;
}