#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n);

    int l = 0; int r = n-1;
    int ans = 2e9;
    while (l < r) {
        int sum = abs(arr[l] + arr[r]);
        ans = min(sum, ans);
        if (sum > 0) {
            l++;
        } else if (sum < 0) {
            r--;
        } else {
            break;
        }
    }
    cout << ans;

    return 0;
}