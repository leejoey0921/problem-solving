#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int size_a, size_b; cin >> size_a >> size_b;

    set<int> A;

    for (int i = 0; i < size_a; i++) {
        int a; cin >> a;
        A.insert(a);
    }

    int size_intersect = 0;

    for (int i = 0; i < size_b; i++) {
        int b; cin >> b;
        if (A.find(b) != A.end()) {
            size_intersect++;
        }
    }

    cout << size_a + size_b - 2*size_intersect;

    return 0;
}