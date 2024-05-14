#include <iostream>

#define MAX_N 100000

using namespace std;

int n, m;
int arr[MAX_N];

int Find(int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if(arr[mid] == target)
            return mid;
        
        if(arr[mid] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }

    return -1;
}

int main() {
    // 입력
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    for(int i = 0; i < m; i++) {
        int x;
        cin >> x;

        // 이진탐색을 진행합니다.
        int index = Find(x);

        if(index >= 0)
            cout << index + 1 << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}