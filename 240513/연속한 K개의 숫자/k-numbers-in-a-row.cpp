#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, k, b; cin >> n >> k >> b;
    int arr[n] = {};

    for (int i; i < b; i++) {
        int x; cin >> x;
        arr[x-1] = 1;
    }

    int count = 0;
    for (int i; i < k; i++) {
        count += arr[i];
    }

    int ans = count;

    for (int i; i <= n-k; i++) {
        count = count - arr[i] + arr[i+k];
        ans = min(ans, count);
    }
    cout << ans;

    return 0;
}