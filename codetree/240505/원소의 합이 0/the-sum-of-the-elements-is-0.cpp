#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    int nums[4][5000];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < n; j++) {
            cin >> nums[i][j];
        }
    }

    auto a = nums[0];
    auto b = nums[1];
    auto c = nums[2];
    auto d = nums[3];
    
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    
    unordered_map<int, int> ab, cd;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ab[a[i] + b[j]]++;
            cd[c[i] + d[j]]++;
        }
    }

    int result = 0;

    auto iab = ab.begin();
    while (iab != ab.end()) {
        if (cd.find(-(*iab).first) != cd.end()) {
            result += (*iab).second * cd[-(*iab).first];
        }
        iab++;
    }
    cout << result;

    return 0;
}