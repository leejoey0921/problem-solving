#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, k; cin >> n >> k;

    unordered_set<int> visited[n];
    int seats[n]; iota(seats, seats + n, 0);

    // insert initial position
    for (int i = 0; i < n; i++) {
        visited[i].insert(i);
    }
    // first iteration
    for (int i = 0; i < k; i++) {
        int a, b; cin >> a >> b; a--; b--;
        // swap and store
        int t = seats[a];
        seats[a] = seats[b]; seats[b] = t;
        visited[seats[a]].insert(a);
        visited[seats[b]].insert(b);
    }

    unordered_set<int> ans_visited[n];
    for (int i = 0; i < n; i++) {
        for (auto x : visited[i]) {
            ans_visited[i].insert(x);
        }
    }
    int ans_seats[n]; 
    copy(seats, seats+n, ans_seats);
    
    for (int i = 0; i < 2; i++) {
        int next_seats[n];
        for (int j = 0; j < n; j++) {
            int next_j = seats[j];
            next_seats[j] = ans_seats[next_j];
            for (auto k : visited[next_j]) {
                ans_visited[next_seats[j]].insert(k);
            }
        }
        copy(next_seats, next_seats + n, ans_seats);
    }

    for (int i = 0; i < n; i++) {
        cout << ans_visited[i].size() << "\n";
    }


    return 0;
}