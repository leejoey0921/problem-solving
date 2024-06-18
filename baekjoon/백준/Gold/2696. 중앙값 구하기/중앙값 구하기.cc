// 중앙값 구하기
// https://www.acmicpc.net/problem/2696

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int n;
		cin >> n;
		priority_queue<int> maxh;
		priority_queue<int, vector<int>, greater<int>> minh;
		vector<int> res;
		for (int i = 0; i < n; i++) {
			int p;
			cin >> p;
			if (maxh.size() > minh.size())
				minh.push(p);
			else
				maxh.push(p);
			if (maxh.size() != 0 && minh.size() != 0) {
				if (maxh.top() > minh.top()) {
					int a = maxh.top();
					int b = minh.top();
					maxh.pop();
					minh.pop();
					maxh.push(b);
					minh.push(a);
				}
			}
			if (i % 2 == 0)
				res.push_back(maxh.top());
		}
		cout << res.size() << '\n';
		for (int i = 0; i < res.size(); i++) {
			cout << res[i] << ' ';
			if (i % 10 == 9)
				cout << '\n';
		}
	}
}
