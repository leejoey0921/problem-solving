#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> m;
set<int> s;
int arr[1010101];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        arr[i] = x;
        s.insert(x);
    }
    int cnt = 0;
    for (int x : s) {
        m[x] = cnt;
        cnt++;
    }


    for (int i = 0; i < n; i++) {
        int x = arr[i];
        cout << m[x] << " ";
    }
    return 0;
}
