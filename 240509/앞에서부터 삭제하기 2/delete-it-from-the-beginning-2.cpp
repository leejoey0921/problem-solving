#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    int arr[n];

    for (int i; i < n; i++) {
        cin >> arr[i];
    }

    priority_queue<int> pq;
    pq.push(-arr[n-1]);
    int sum = arr[n-1];
    float ans = 0.0;

    for (int l = n-2; l > 0; l--) {
        sum += arr[l];
        pq.push(-arr[l]);
        float avg = (float)(sum + pq.top()) / (float)(n - l - 1);
        if (avg > ans) ans = avg;
    }
    cout.precision(2); cout << fixed;
    cout << ans;

    return 0;
}