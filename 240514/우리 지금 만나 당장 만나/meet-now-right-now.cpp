#include <iostream>
#include <algorithm>

#define MAX_N 100000

using namespace std;

// 변수 선언
int n;
int x[MAX_N], v[MAX_N];
 
// time시간 동안 모든 사람이 도착할 수 있는지 판단합니다.
bool isPossible(double time) {
    double max_x1 = x[0] - v[0] * time;
    double min_x2 = x[0] + v[0] * time;
    for(int i = 1; i < n; i++) {
        // i번 사람은 time시간에 x1 ~ x2 사이에만 있을 수 있습니다.
        double x1 = x[i] - v[i] * time;
        double x2 = x[i] + v[i] * time;

        // x1들 중 최댓값을 찾아 max_x1에 저장합니다.
        max_x1 = max(max_x1, x1);

        // x2들 중 최솟값을 찾아 min_x2에 저장합니다.
        min_x2 = min(min_x2, x2);
    }

    // 가능한 구간이 존재하면 모든 사람이 한 곳에 모일 수 있습니다.
    return max_x1 <= min_x2;
}
 
int main(){
    // 입력:
    cin >> n;
    for(int i = 0; i < n; i++) cin >> x[i];
    for(int i = 0; i < n; i++) cin >> v[i];

    double lo = 0;                   // 답이 될 수 있는 가장 작은 숫자 값을 설정합니다.
    double hi = 1e9;                 // 답이 될 수 있는 가장 큰 숫자 값을 설정합니다.
    double ans = 1e9;                // 답을 저장합니다.

    for(int i = 1; i <= 100; i++) {  // 실수형이기 때문에 횟수를 정해 이진 탐색을 수행합니다. 
        double mid = (lo + hi) / 2;  // 가운데 위치를 선택합니다.
        if(isPossible(mid)) {        // 결정문제에 대한 답이 Yes라면
            hi = mid;                // 왼쪽에 조건을 만족하는 숫자가 더 있을 가능성 때문에 hi를 바꿔줍니다.
            ans = min(ans, mid);     // 답의 후보들 중 최솟값을 계속 갱신해줍니다.
        }
        else lo = mid;               // 결정문제에 대한 답이 No라면 lo를 바꿔줍니다.
    }
    
    cout << fixed;
    cout.precision(4);
    
    // 정답을 출력합니다.
    cout << ans;

    return 0;
}