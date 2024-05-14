#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n, m; cin >> n >> m;

    map<ll, int> freq;

    for (int i; i < n; i++) {
        ll x; cin >> x;
        freq[x]++;
    }

    for (int i; i < m; i++) {
        ll q; cin >> q;
        cout << freq[q] << "\n";
    }


    return 0;
}