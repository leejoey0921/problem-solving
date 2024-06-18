#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

map<ll, ll> memo;

ll powMod(ll x, ll exp, ll mod) {
    if (memo.find(exp) != memo.end()) return memo[exp];
    ll res;
    if (exp == 1) res = x % mod;
    else res = (powMod(x, exp/2, mod) * powMod(x, (exp+1)/2, mod)) % mod;
    memo[exp] = res;
    return res;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    ll a, b, c; cin >> a >> b >> c;

    cout << powMod(a, b, c);

    return 0;
}
