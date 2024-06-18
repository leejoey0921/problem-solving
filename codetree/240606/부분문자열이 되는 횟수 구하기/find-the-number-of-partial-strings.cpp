#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    string A, B; cin >> A >> B;
    int n = A.length();
    int order[n];
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        order[i] = --x;
    }

    int l = 0; int r = n;
    int ans = -1;

    while (l <= r) {
        int mid = (l + r) / 2;

        string tmp = A;
        for (int i = 0; i < mid; i++) {
            tmp[order[i]] = ' ';
        }

        int aIt = 0; int bIt = 0;
        while (aIt < n && bIt < B.length()) {
            if (tmp[aIt] == B[bIt]) {
                bIt++;
            }
            aIt++;
        }

        if (bIt == B.length()) {
            l = mid + 1;
            ans = max(ans, mid);
        } else {
            r = mid - 1;
        }
    }

    cout << ++ans;


    return 0;
}