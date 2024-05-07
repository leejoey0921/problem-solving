#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n, k; cin >> n >> k;
    unordered_map<int, int> m;
    int arr[n+1];

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    int ans = 0;
    int j = 0;
    for (int i = 1; i <= n; i++) {
        while (j + 1 <= n && m[arr[j + 1]] < k) {
            m[arr[j + 1]]++;
            j++;
        }
        ans = max(ans, j - i + 1);
        
        m[arr[i]]--;
    }

    cout << ans;


    return 0;
}