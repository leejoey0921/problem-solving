#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, k; cin >> n >> k;
    int arr[n+1] = {0};

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    
    for (int i = 1; i <= n; i++) {
        arr[i] += arr[i-1];
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] - arr[j] == k) {
                ans++;
            }
        }
    }
    cout << ans;

    return 0;
}