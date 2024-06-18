#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    pii cnts[41]; // {0 count, 1 count}

    cnts[0] = {1, 0};
    cnts[1] = {0, 1};

    for (int i = 2; i <= 40; i++) {
        pii p1 = cnts[i-2];
        pii p2 = cnts[i-1];
        cnts[i] = {p1.first + p2.first, p1.second + p2.second};
    }

    int n; cin >> n;

    while (n > 0) {
        int q; cin >> q;
        cout << cnts[q].first << " " << cnts[q].second << "\n";
        n--;
    }

    return 0;
}
