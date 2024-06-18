#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

vector<pii> tree[101010];
int dists[101010];
bool visited[101010];
int ans = 0;

int dfs(int cv) {
//    cout << "push " << cv << endl;
    vector<int> childDists;
    int childCnt = 0;
    for (auto [nv, nw] : tree[cv]) {
        if (visited[nv]) continue;
        childCnt++;
        visited[nv] = true;
        int childWeight = nw + dfs(nv);
        childDists.push_back(childWeight);
    }
    if (childCnt == 0) return 0;

    int l1 = 0; int l2 = 0;
    for (int d : childDists) {
        if (d > l1) {
            l2 = l1;
            l1 = d;
        } else if (d > l2) {
            l2 = d;
        }
    }
    ans = max(ans, l1 + l2);
//    cout << "pop " << cv << " " << l1 << endl;
    return l1;
}

int main() {
    // https://www.acmicpc.net/board/view/123573
    /**
     * root에서 leaf까지 재귀적으로 내려간 다음,
     * leaf에서 올라오면서 부모 노드에 거리의 누적을 저장
     * 부모로 올라가면, 서로 가장 먼 자식의 거리를 더해서 저장
     * 이렇게 재귀적으로 올라가면 됨
     */
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    pii root = {0, 0}; // node number, branch count
    for (int i = 0; i < n; i++) {
        int v; cin >> v;
        int cnt = 0;
        while (true) {
            int e, w;
            cin >> e;
            if (e == -1) break;
            cin >> w;
            tree[v].push_back({e, w});
            cnt++;
        }
        if (cnt > root.second) root = {v, cnt};
    }
    visited[root.first] = true;
    dfs(root.first);
    cout << ans;
    return 0;
}
