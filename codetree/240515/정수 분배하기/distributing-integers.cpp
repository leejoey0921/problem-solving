#include<bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n, m; cin >> n >> m;
    vector<int> v;

    int max_val = 0;
    for (int i; i < n; i++) {
        int x; cin >> x;
        v.push_back(x);

    }

    int l = 0; int r = 1e5;

	while (l < r) {
		int mid = (l + r + 1) / 2;

		int cnt = 0;
		for (int i = 0; i < n; i++) {
			cnt += v[i] / mid;
		}

		if (cnt < m) {
            r = mid - 1;
        } else {
            l = mid;
        }
	}

    cout << r;

    return 0;
}