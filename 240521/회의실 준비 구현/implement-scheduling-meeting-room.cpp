#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;


int n;
vector<pair<int, int> > meetings;

int ans;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        int s, e;
        cin >> s >> e;
        meetings.push_back(make_pair(e, s));
    }


    sort(meetings.begin(), meetings.end());

    int last_e = -1;
    for(int i = 0; i < n; i++) {
        int s, e;
        tie(e, s) = meetings[i];

        if(last_e <= s) {
            ans++;
            last_e = e;
        }
    }

    cout << ans;
    return 0;
}