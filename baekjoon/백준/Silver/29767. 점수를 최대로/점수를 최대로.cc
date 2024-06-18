#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    int n, k; cin >> n >> k;
    ll rooms[n+1];
    fill_n(rooms, n+1, (ll) 0);
    for (int i = 1; i <= n; i++) {
        ll x; cin >> x;
        rooms[i] = x + rooms[i-1];
    }
    sort(rooms+1, rooms+n+1);
    cout << accumulate(rooms+n-k+1, rooms+n+1, (ll) 0);

    return 0;
}