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
                unordered_set<string> a_tags;
                for (int l = 0; l < n; l++) {
                    string a_tag = a[l].substr(i, 1) + a[l].substr(j, 1) + a[l].substr(k, 1);
                    a_tags.insert(a_tag);
                    
                }

                string b_tag;
                bool valid = true;
                for (int l = 0; l < n; l++) {
                    b_tag = b[l].substr(i, 1) + b[l].substr(j, 1) + b[l].substr(k, 1); 
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