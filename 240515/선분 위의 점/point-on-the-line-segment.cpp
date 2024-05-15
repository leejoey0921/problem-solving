#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n, m; cin >> n >> m;
    int points[n];

    for (int i; i < n; i++) {
        cin >> points[i];
    }

    while(m--) {
        int s, e; cin >> s >> e;
        
        // min idx of item larger or equal to s
        int min_idx;
        int l = 0; int r = n-1;
        while (l < r) {
            int m = (l + r) / 2;
            if (points[m] < s) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        if (points[l] < s) {
            cout << "0\n";;
            continue;
        }
        min_idx = l;
        

        // max indx of item smaller or equal to e
        int max_idx;
        l = 0; r = n-1;
        while (l < r) {
            int m = ((l + r) / 2) + 1;
            if (points[m] > e) {
                r = m - 1;
            } else {
                l = m;
            }
        }
        if (points[r] > e) {
            cout << "0\n";;
            continue;
        }
        max_idx = r;

        cout << max(-1, max_idx - min_idx) + 1 << "\n";
    }



    return 0;
}