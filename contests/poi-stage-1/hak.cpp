#include <bits/stdc++.h>
using namespace std;

void solve() {
    int k { 0 };
    cin >> k;
    vector<deque<int>> goal (k);
    int n { 0 };
    for (int i = 0; i < k; i++) {
        int c;
        cin >> c;
        n+=c;
        for (int j = 0; j < c; j++) {
            int a;
            cin >> a;
            goal[i].push_back(a);
        }
    }
    int temp { 0 };
    vector<int> val (n+1);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < static_cast<int>(goal[i].size()); j++) {
            val[goal[i][j]] = j+temp; 
        }
        temp += static_cast<int>(goal[i].size());
    }
    vector<deque<int>> towers (k);
    for (int i = 0; i < k; i++) {
        int c;
        cin >> c;
        for (int j = 0; j < c; j++) {
            int a;
            cin >> a;
            towers[i].push_back(a);
        }
    }
    vector<pair<int, int>> seq;
    for (int i = 2; i < k; i++) {
        while (!towers[i].empty()) {
            seq.push_back({i, 0});
            towers[0].push_back(towers[i].front()); 
            towers[i].pop_front();
        }
    }
    int small { -1 };
    if (towers[0].size() != towers[1].size() && abs(static_cast<int>(towers[0].size()-towers[1].size())) != 1) {
        if (towers[0].size() < towers[1].size()) { small = 0; }
        else { small = 1; }
    }
    while (towers[0].size() != towers[1].size() && abs(static_cast<int>(towers[0].size()-towers[1].size())) != 1) {
        if (small == 0) {
            seq.push_back({1, 0});
            towers[0].push_back(towers[1].front());
            towers[1].pop_front();
        }
        else {
            seq.push_back({0, 1});
            towers[1].push_back(towers[0].front());
            towers[0].pop_front();
        }
    }
    int grp { 1 };
    while (grp < static_cast<int>(towers[0].size()) || grp < static_cast<int>(towers[1].size())) {
        int remFir { static_cast<int>(towers[0].size()) };
        int remSec { static_cast<int>(towers[1].size()) };
        int cur { 0 };
        while (remFir > 0 || remSec > 0) {
            int fir { min(grp, remFir) };
            int sec { min(grp, remSec) };
            remFir -= fir;
            remSec -= sec;
            while (fir > 0 || sec > 0) {
                if (fir > 0 && sec > 0 && val[towers[0].front()] <= val[towers[1].front()]) {
                    seq.push_back({0, cur});
                    towers[cur].push_back(towers[0].front());
                    towers[0].pop_front();
                    fir--;
                } 
                else if (fir > 0 && sec > 0 && val[towers[0].front()] > val[towers[1].front()]) {
                    seq.push_back({1, cur});
                    towers[cur].push_back(towers[1].front());
                    towers[1].pop_front();
                    sec--;
                }
                if (fir == 0 && sec > 0) {
                    seq.push_back({1, cur});
                    towers[cur].push_back(towers[1].front());
                    towers[1].pop_front();
                    sec--;
                }
                else if (sec == 0 && fir > 0) {
                    seq.push_back({0, cur});
                    towers[cur].push_back(towers[0].front());
                    towers[0].pop_front();
                    fir--;
                }
            }  
            if (cur == 1) { cur = 0; }
            else { cur = 1; }
        }
        grp *= 2;
    }
    while (!towers[0].empty() || !towers[1].empty()) {
        for (int i = 0; i < k; i++) {
            if (!goal[i].empty() && !towers[0].empty() && towers[0].front() == goal[i].front()) {
                seq.push_back({0, i});
                towers[0].pop_front();
                goal[i].pop_front();
            }
            if (!goal[i].empty() && !towers[1].empty() && towers[1].front() == goal[i].front()) {
                seq.push_back({1, i});
                towers[1].pop_front();
                goal[i].pop_front();
            }
        } 
    }
    cout << seq.size() << "\n";
    for (const auto& a : seq) {
        cout << a.first+1 << " " << a.second+1 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
