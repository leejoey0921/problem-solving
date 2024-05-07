#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, s; cin >> n >> s;

    int arr[n];

    for (int i; i < n; i++) {
        cin >> arr[i];
    }

    int sum = arr[0];
    if (sum >= s) {
        cout << 1;
        return 0;
    }
    int ans = 1e8;
    
    for (int i; i < n; i++) {
        for (int j = 1; j < n && sum < s; j++) {
            sum += j;
            ans = min(j - i + 1, ans);
        }
    }

    cout << ans;
    return 0;
}