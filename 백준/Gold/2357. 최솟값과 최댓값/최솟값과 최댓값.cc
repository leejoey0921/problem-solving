#include <bits/stdc++.h>
using namespace std;

struct Node {
    int start;
    int end;
    int minVal = 2e9;
    int maxVal = 0;
};

typedef pair<int, int> pii;

/*
 * 0
 * 1
 * 2 3
 * 4 5 6
 * 7 8 9 10
 *
 * 9
 * 9 7
 * 5 9 7 6
 * 5 1 4 9 3 7 2 6
 */

pii query(Node tree[], int leafCnt, int idx, int s, int e) {
    if (idx < 1 || idx >= 2*leafCnt) return {2e9, 0};

    Node n = tree[idx];
    if (n.end < s || n.start > e) return {2e9, 0};
    else if (n.start >= s && n.end <= e) return {n.minVal, n.maxVal};

    pii left = query(tree, leafCnt, idx<<1, s, e);
    pii right = query(tree, leafCnt, (idx<<1)+1, s, e);

    return {
      min(left.first, right.first),
      max(left.second, right.second)
    };

}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;

    int leafCnt = 2;
    while (leafCnt < n) leafCnt <<= 1;

    Node tree[2 * leafCnt]; // min, max
    fill_n(tree, leafCnt, (Node) {0, 0});
    for (int i = 1; i <= leafCnt; i++) tree[i + leafCnt - 1] = {i, i};

    for (int i = leafCnt; i < leafCnt + n; i++) {
        int x; cin >> x;
        tree[i].minVal = x; tree[i].maxVal = x;
    }

    for (int i = leafCnt-1; i > 0; i--) {
        Node left = tree[i<<1];
        Node right = tree[(i<<1)+1];
        tree[i] = {
            min(left.start, right.start),
            max(left.end, right.end),
            min(left.minVal, right.minVal),
            max(left.maxVal, right.maxVal),
        };
    }

//    for (int i = 1; i < leafCnt*2; i++) {
//        Node n = tree[i];
//        cout << n.start << " " << n.end << " " << n.minVal << " " << n.maxVal << endl;
//    }

    for (int qCnt = 0; qCnt < m; qCnt++) {
        int s, e; cin >> s >> e;
        pii ans = query(tree, leafCnt, 1, s, e);

        cout << ans.first << " " << ans.second << "\n";
    }

    return 0;
}
