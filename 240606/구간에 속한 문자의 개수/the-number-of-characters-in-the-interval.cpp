#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n, m, k; cin >> n >> m >> k;

    int A[n+1][m+1] = {};
    int B[n+1][m+1] = {};
    int C[n+1][m+1] = {};

    for (int i = 1; i <= n; i++) {
        string s; cin >> s;
        for (int j = 1; j <= m; j++) {
            char c = s[j-1];
            if (c == 'a') {
                A[i][j] = 1;
            } else if (c == 'b') {
                B[i][j] = 1;
            } else {
                C[i][j] = 1;
            }
        }
    }

    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            A[i][j] += A[i][j-1];
            B[i][j] += B[i][j-1];
            C[i][j] += C[i][j-1];
        }
    }

    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            A[i][j] += A[i-1][j];
            B[i][j] += B[i-1][j];
            C[i][j] += C[i-1][j];
        }
    }

    for (int q_cnt = 0; q_cnt < k; q_cnt++) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        x1--; y1--;

        cout << A[x2][y2] - A[x2][y1] - A[x1][y2] + A[x1][y1] << " ";
        cout << B[x2][y2] - B[x2][y1] - B[x1][y2] + B[x1][y1] << " ";
        cout << C[x2][y2] - C[x2][y1] - C[x1][y2] + C[x1][y1] << "\n";
    }


    return 0;
}