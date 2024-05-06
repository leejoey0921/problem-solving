#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n, m; cin >> n >> m;
    unordered_set<int> groups[m];

    for (int i = 0; i < m; i++) {
        int size; cin >> size;
        for (int j = 0; j < size; j++) {
            int member; cin >> member;
            groups[i].insert(member);
        }
    }

    unordered_set<int> invited; invited.insert(1);
    
    vector<int> v; v.push_back(1);
    while (!v.empty()) {
        int it = v.back(); v.pop_back();
        for (auto &group : groups) {
            if (group.size() == 0) {
                continue;
            }
            if (group.find(it) != group.end()) {
                group.erase(it);
            }
            if (group.size() == 1) {
                auto add = group.begin();
                v.push_back(*add);
                invited.insert(*add);

                group.erase(add);

                
            }
        }
    }
    cout << invited.size();
    return 0;
}