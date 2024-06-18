#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

#define MAX_M 100000
#define MAX_NUM (long long)1e14

using namespace std;

// 변수 선언
int n, m;
int arr[MAX_M];

// 모두 통과시키는데 걸리는 시간을 transit_time라 했을 때
// n개의 물건을 모두 통과시킬 수 있는지를 확인합니다.
bool IsPossible(long long transit_time) {
    // 통과시킬 수 있는 물건의 수를 계산합니다.
    long long cnt = 0;
    for(int i = 0; i < m; i++) {
        // 어차피 transit_time만큼 걸릴 거라면
        // 현재 통로를 이용해서는
        // transit_time / arr[i] 만큼의 물건을
        // 통과시키는 것이 항상 좋습니다.
        cnt += transit_time / arr[i];
    }

    // 통과시킬 수 있는 물건의 수가 n개 이상이라면 true
    // 아니라면 불가능한 것이므로 false를 반환합니다.
    return cnt >= n;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    // 입력
    cin >> n >> m;
    for(int i = 0; i < m; i++)
        cin >> arr[i];
    
    long long left = 1;                      // 답이 될 수 있는 가장 작은 숫자 값을 설정합니다.
    long long right = MAX_NUM;               // 답이 될 수 있는 가장 큰 숫자 값을 설정합니다.
    long long ans = MAX_NUM;                 // 답을 저장합니다.
    
    while (left <= right) {                  // [left, right]가 유효한 구간이면 계속 수행합니다.
        long long mid = (left + right) / 2;  // 가운데 위치를 선택합니다.
        if(IsPossible(mid)) {                // 결정문제에 대한 답이 Yes라면
            right = mid - 1;                 // 왼쪽에 조건을 만족하는 숫자가 더 있을 가능성 때문에 right를 바꿔줍니다.
            ans = min(ans, mid);             // 답의 후보들 중 최솟값을 계속 갱신해줍니다.
        }
        else                               
            left = mid + 1;                  // 결정문제에 대한 답이 No라면 left를 바꿔줍니다.
    }

    cout << ans;
    return 0;
}