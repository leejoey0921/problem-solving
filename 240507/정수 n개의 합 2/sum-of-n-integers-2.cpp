#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n, k; cin >> n >> k;
    int arr[n];

    for (int i; i < n; i++) {
        cin >> arr[i];
    }

    int sum = 0;

    for (int i; i < k; i++) {
        sum += arr[i];
    }

    int ans = sum;
    for (int i; i < n-k; i++) {
        sum = sum - arr[i] + arr[i+k];
        ans = max(ans, sum);
    }

    cout << ans;

    return 0;
}