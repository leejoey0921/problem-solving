#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n; cin >> n;
    vector<string> seqs;
    vector<pair<ll, string>> scores;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        seqs.push_back(s);
    }

    for (string seq: seqs) {
        ll score = 0;
        ll cur = 5e5;
        for (char c : seq) {
            if (c == '(') score += cur;
            else score -= cur;
            cur--;
        }
        scores.push_back({-score, seq});
    }
    sort(scores.begin(), scores.end());

    string res_seq = "";
    for (auto [score, seq] : scores) {
        res_seq += seq;
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