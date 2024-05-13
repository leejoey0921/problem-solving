#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, k, b; cin >> n >> k >> b;
    int arr[n];
    fill_n(arr, n, 1);

    for (int i; i < b; i++) {
        int x; cin >> x;
        arr[x-1] = 0;
    }

    int count = 0;
    for (int i; i < k; i++) {
        count += arr[i];
    }

    int ans = k - count;

    for (int i; i <= n-k; i++) {
        count = count - arr[i] + arr[i+k-1];
        ans = min(ans, k - count);
    }
    cout << ans;

    return 0;
}