#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n, k;
    int arr[10**5];
    unordered_map<int, int> freq;
    vector<pair<int, int>> v;

    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        freq[arr[i]]++;
    }

    for(auto it = freq.begin(); it != freq.end(); it++) {
        v.push_back({it->second, it->first});
    }

    sort(v.begin(), b.end());

    for(int i = (int) v.size() - 1; i >= (int) v.size() - k; i--) {
        cout << v[i].second << " ";
    }

    return 0;
}