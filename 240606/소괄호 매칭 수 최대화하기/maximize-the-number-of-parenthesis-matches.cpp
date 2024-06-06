#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n; cin >> n;
    vector<string> seqs;
    map<string, pii> cnts;

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        seqs.push_back(s);
    }

    for (string s : seqs) {
        int open = 0; int close = 0;
        for (char c : s) {
            if (c == '(') open++;
            else close++;
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

    string res_seq = "";
    for (string s : seqs) {
        res_seq += s;
    }

    ll open_cnt = 0;
    ll ans = 0;
    for (char c : res_seq) {
        if (c == '(') open_cnt++;
        else ans += open_cnt;
    }

    cout << ans;   

    return 0;
}