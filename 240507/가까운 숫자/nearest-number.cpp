#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    set<int> points; points.insert(0);
    set<int> diffs;

    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        points.insert(x);

        auto q = points.upper_bound(x);
        if (q != points.end()) {
            diffs.insert(*q - x);
        }
        q--;
        if (q != points.begin()) {
            diffs.insert(x - *(--q));
        }

        cout << *diffs.begin() << "\n";
    }

    return 0;
}