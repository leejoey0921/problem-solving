#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;

    vector<int> nums[n+1];
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            int x; cin >> x;
            nums[i].push_back(x);
        }
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            int left = (j > 0) ? nums[i-1][j-1] : -1;
            int right = (j < i - 1) ? nums[i-1][j] : -1;
            nums[i][j] += max(left, right);
        }
    }

    cout << *max_element(nums[n].begin(), nums[n].end());

    return 0;
}
