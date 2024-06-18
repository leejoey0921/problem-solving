#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n; cin >> n;
    vector<string> seqs;
    map<string, pii> cnts;
    ll ans = 0;

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        seqs.push_back(s);
    }

    for (string s : seqs) {
        int open = 0; int close = 0;
        for (char c : s) {
            if (c == '(') open++;
            else {
                close++;
                ans += open;
            }
        }
        cnts[s] = {open, close};
    }

    sort(
        seqs.begin(),
        seqs.end(),
        [&](string s1, string s2) {
            auto [open1, close1] = cnts[s1];
            auto [open2, close2] = cnts[s2];
            return open1 * close2 > open2 * close1;
        }
    );

    int open_sum = 0;
    for (string s : seqs) {
        int open = cnts[s].first;
        int close = cnts[s].second;

        ans += (ll) open_sum * close;

        open_sum += open;
    }

    cout << ans;   

    return 0;
}