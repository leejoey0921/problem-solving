#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n, m; cin >> n >> m;

    int A[n], B[m];

    for (int i; i < n; i++) {
        cin >> A[i];
    }
    for (int i; i < m; i++) {
        cin >> B[i];
    }

    int i = 0; int j = 0;
    while (i < n && j < m) {
        if (A[i] == B[j]) {
            j++;
        }
        i++;
    }

    if (j == m) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}