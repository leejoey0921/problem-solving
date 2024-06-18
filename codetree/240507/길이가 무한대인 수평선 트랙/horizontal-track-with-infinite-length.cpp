#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, t; cin >> n >> t;
    map<long long, long long> positions; // -final: initial

    for (int i; i < n; i++) {
        long long x, v; cin >> x >> v;
        long long fin = -(x + v*t);
        if (positions.find(fin) == positions.end() || positions[fin] > x) {
            positions[fin] = x;
        }
    }

    auto hi = positions.begin();
    while (hi != --positions.end()) {
        auto lo = positions.end();
        while (lo != hi) {
            if ((*lo).second > (*hi).second) {
                lo = positions.erase(lo);
            }
            lo--;
        }
        hi++;
    }
    
    cout << positions.size();
    return 0;
}