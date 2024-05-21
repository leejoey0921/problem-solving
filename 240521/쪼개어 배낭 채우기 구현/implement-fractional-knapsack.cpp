#include <bits/stdc++.h>
using namespace std;

typedef pair<double, double> pdd;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    double n, m; cin >> n >> m;
    vector<pdd> gems;

    for (int i = 0; i < n; i++) {
        double w, v; cin >> w >> v;
        gems.push_back({w, v});
    }

    sort(gems.begin(), gems.end(), [&](pdd p, pdd q) {
        return (p.first / p.second) < (q.first / q.second);
    });

    double acc_v = 0;
    double acc_w = 0;

    for (auto [w, v] : gems) {
        if (acc_w + w < m) {
            acc_v += v;
            acc_w += w;
        } else {
            acc_v += (m - acc_w) * ((double) v / (double) w);
            break;
        }
    }
    cout << fixed;
    cout.precision(3);
    cout << acc_v;

    return 0;
}