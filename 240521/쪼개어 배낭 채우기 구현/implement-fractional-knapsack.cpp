#include <bits/stdc++.h>

using namespace std;

// 변수 선언
int n, m;
vector<tuple<double, int, int> > jewels;
double ans;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    // 입력:
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int w, v;
        cin >> w >> v;
        jewels.push_back(make_tuple(-(double)v / w, w, v));
    }

    // 가치 / 무게가 내림차순이 되도록 정렬합니다.
    sort(jewels.begin(), jewels.end());

    for(int i = 0; i < n; i++) {
        int w, v;
        tie(ignore, w, v) = jewels[i];
        // 현재 보석을 온전히 다 담을 수 있다면 그대로 담아줍니다.
        if(m >= w) {
            m -= w;
            ans += v;
        }
        // 만약 부분만 담을 수 있다면
        // 비율에 맞춰 담아준 뒤 종료합니다.
        else {
            ans += (double)m / w * v;
            break;
        }
    }

    cout << fixed;
    cout.precision(3);
    cout << ans;
    return 0;
}