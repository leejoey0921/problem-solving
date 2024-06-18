#include <iostream>

#define MAX_N 100

using namespace std;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

// 변수 선언
int n;
int board[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

// dfs를 이용해 색칠하고 몇 칸이 칠해졌는지 확인합니다.
int dfs(int x, int y, int d) {
    if(visited[x][y])
        return 0;
    
    visited[x][y] = true;
    int count = 1;
    for(int dir = 0; dir < 4; dir++) {
        int next_x = x + dx[dir];
        int next_y = y + dy[dir];
        if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < n &&
                abs(board[next_x][next_y] - board[x][y]) <= d) {
            count += dfs(next_x, next_y, d);
        }
    }
    return count;
}

// d 이하로 인접한 칸을 색칠한다고 할 때,
// 색칠된 칸이 전체 칸의 반 이상이 될 수 있는지 판단합니다.
bool is_possible(int d) {
    // visited 배열을 초기화합니다.
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            visited[i][j] = false;

    // 모든 구역에 대해 절반 이상이 칠해지는 구역이 있는지 확인합니다.
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!visited[i][j]) {
                if(dfs(i, j, d) * 2 >= n*n) {
                    return true;
                }
            }
        }
    }

    // 절반 이상이 칠해지는 구역이 없다면 false를 반환합니다.
    return false;
}

int main() {
    // 입력:
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> board[i][j];

    int lo = 0;                       // 답이 될 수 있는 가장 작은 숫자 값을 설정합니다.
    int hi = 1000000;                 // 답이 될 수 있는 가장 큰 숫자 값을 설정합니다.
    int ans = 0;                      // 답을 저장합니다.

    while(lo <= hi) {                 // [lo, hi]가 유효한 구간이면 계속 수행합니다.
        int mid = (lo + hi) / 2;      // 가운데 위치를 선택합니다.
        if(is_possible(mid)) {        // 결정문제에 대한 답이 Yes라면
            hi = mid - 1;             // 왼쪽에 조건을 만족하는 숫자가 더 있을 가능성 때문에 hi를 바꿔줍니다.
            ans = mid;                // 답의 후보들 중 최댓값을 계속 갱신해줍니다.
        }
        else
            lo = mid + 1;             // 결정문제에 대한 답이 No라면 lo를 바꿔줍니다.
    }

    

    // 정답을 출력합니다.
    cout << ans;
    return 0;
}