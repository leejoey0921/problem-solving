#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    ll s, e; cin >> s >> e;

    ll primeMax = (ll) sqrt(e);

    bool isPrime[primeMax+1]; // 0...primeMax
    fill_n(isPrime, primeMax+1, true);
    vector<ll> primes;

    for (ll i = 2; i <= primeMax; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (ll mul = i*2; mul <= primeMax; mul += i) {
                isPrime[mul] = false;
            }
        }
    }

    unordered_set<ll> sq_mul;
    for (ll p : primes) {
        ll sq = p*p;
        ll start = (s / sq + (s % sq != 0)) * sq;
        for (ll mul = start; mul <= e; mul += sq) {
            sq_mul.insert(mul);
        }
    }
    cout << e - s + 1 - sq_mul.size();

    return 0;
}
