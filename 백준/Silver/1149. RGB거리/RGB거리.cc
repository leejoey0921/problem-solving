#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    int costs[n][3];
    for (int i = 0; i < n; i++) {
        cin >> costs[i][0] >> costs[i][1] >> costs[i][2];
    }

    for (int i = n-1; i > 0; i--) {
        costs[i-1][0] += min(costs[i][1], costs[i][2]);
        costs[i-1][1] += min(costs[i][0], costs[i][2]);
        costs[i-1][2] += min(costs[i][0], costs[i][1]);
    }

    cout << *min_element(costs[0], costs[0]+3);

    return 0;
}
