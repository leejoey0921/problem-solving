#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    string a[n], b[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    
    int ans = 0;

    for (int i = 0; i < m; i++) {
        for (int j = i+1; j < m; j++) {
            for (int k = j+1; k < m; k++) {
                unordered_set<int> a_tags;
                for (int l = 0; l < n; l++) {
                    int a_tag = (a[l][i] << 8) + (a[l][j] << 4) + a[l][k];
                    a_tags.insert(a_tag);
                    
                }

                int b_tag;
                bool valid = true;
                for (int l = 0; l < n; l++) {
                    b_tag = (b[l][i] << 8) + (b[l][j] << 4) + b[l][k];
                    if (a_tags.find(b_tag) != a_tags.end()) {
                        valid = false;
                        break;
                    }
                }
                if (valid) ans++;
            }
        }
    }
    cout << ans;
    return 0;
}