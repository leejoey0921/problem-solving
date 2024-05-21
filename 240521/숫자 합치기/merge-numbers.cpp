#include <iostream>
#include <queue>

#define MAX_N 100000

using namespace std;

// 변수 선언
int n;
int arr[MAX_N];

priority_queue<int> pq;
int ans;

int main() {
    // 입력:
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    // 우선순위 큐에 원소들을 전부 넣어줍니다.
    // 작은 숫자 2개를 골라 합치는 것이 항상 유리함을 이용해야 하므로
    // 작은 숫자가 골라질 수 있도록
    // 숫자에 -를 붙여 넣어줘야 함에 유의합니다.
    for(int i = 0; i < n; i++)
        pq.push(-arr[i]);

    // 원소가 2개 이상이면 계속
    // 가장 작은 숫자 2개를 골라
    // 합치는 것을 반복합니다.
    while(pq.size() > 1) {
        int x1 = pq.top(); pq.pop();
        int x2 = pq.top(); pq.pop();
        x1 = -x1; x2 = -x2;

        // 가장 작은 숫자 2개를 더하기 위한 비용을 답에 더해주고,
        // 두 숫자를 합친 결과를 우선순위 큐에 다시 넣어줍니다.
        ans += (x1 + x2);
        pq.push(-(x1 + x2));
    }

    cout << ans;
    return 0;
}