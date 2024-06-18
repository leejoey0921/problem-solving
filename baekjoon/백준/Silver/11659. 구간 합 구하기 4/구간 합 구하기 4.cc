#include <bits/stdc++.h>
using namespace std;

#define MAX 101010

typedef long long ll;

ll arr[MAX];

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++) {
        arr[i] += arr[i-1];
    }

    for (int i = 0; i < m; i++) {
        int s, e; cin >> s >> e;
        cout << arr[e] - arr[s-1] << "\n";
    }
    return 0;
}
