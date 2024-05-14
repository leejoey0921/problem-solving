#include <iostream>
#include <algorithm>
#include <climits>

#define MAX_N 10000
#define MAX_NUM 100000

using namespace std;

// 변수 선언
int n, m;
int arr[MAX_N];

// 숫자 k를 만든다고 헀을 때
// 블럭을 m개 만들 수 있을지 판단합니다.
bool IsPossible(int k) {
    // 만들 수 있는 블럭의 수를 계산합니다.
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        // arr[i] / k개 만큼의
        // 블럭을 만들어 줄 수 있습니다.
        cnt += arr[i] / k;
    }

    // 만들 수 있는 블럭의 수가 m개 이상이라면 true
    // 아니라면 불가능한 것이므로 false를 반환합니다.
    return cnt >= m;
}

int main() {
    // 입력
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    int left = 1;                          // 답이 될 수 있는 가장 작은 숫자 값을 설정합니다.
    int right = MAX_NUM;                   // 답이 될 수 있는  가장 큰 숫자 값을 설정합니다.
    int ans = 0;                           // 답을 저장합니다.
    
    while (left <= right) {                // [left, right]가 유효한 구간이면 계속 수행합니다.
        int mid = (left + right) / 2;      // 가운데 위치를 선택합니다.
        if(IsPossible(mid)) {              // 결정문제에 대한 답이 Yes라면
            left = mid + 1;                // 오른쪽에 조건을 만족하는 숫자가 더 있을 가능성 때문에 left를 바꿔줍니다.
            ans = max(ans, mid);           // 답의 후보들 중 최댓값을 계속 갱신해줍니다.
        }
        else                               
            right = mid - 1;               // 결정문제에 대한 답이 No라면 right를 바꿔줍니다.
    }

    cout << ans;
    return 0;
}