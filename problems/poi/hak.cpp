#include <bits/stdc++.h>
using namespace std;

void solve() {
    int k { 0 };
    cin >> k;
    int n { 0 };
    vector<deque<int>> goal (k);
    vector<int> whichTower;
    for (int i = 0; i < k; i++) {
        int c { 0 };
        cin >> c;
        n+=c;
        for (int j = 0; j < c; j++) {
            int a;
            cin >> a;
            goal[i].push_back(a-1);
        }
    }
    whichTower.resize(n);
    vector<deque<int>> towers (k);
    for (int i = 0; i < k; i++) {
        int c;
        cin >> c;
        for (int j = 0; j < c; j++) {
            int a;
            cin >> a;
            towers[i].push_back(a-1);
        }
    }
    for (int i = 0; i < k; i++) {
        for (const int& b : towers[i]) {
            whichTower[b] = i; 
        }
    }
    int ans { 0 };
    vector<pair<int, int>> seq;
    vector<deque<int>> line { goal };
    for (int i = 0; i < k; i++) {
        while (!line[i].empty()) {
            int ring { line[i].front() };         
            int tow { whichTower[ring] };
            while (towers[tow].front() != ring) {
                ans++; 
                seq.push_back({tow+1, tow+1});
                towers[tow].push_back(towers[tow].front());
                towers[tow].pop_front();
            }
            ans++;
            seq.push_back({tow+1, i+1});
            whichTower[towers[tow].front()] = i;
            towers[i].push_back(towers[tow].front());
            towers[tow].pop_front();
            line[i].pop_front();
        }
    }
    for (int i = 0; i < k; i++) {
        while (towers[i].front() != goal[i].front()) {
            ans++; 
            seq.push_back({i+1, i+1});
            towers[i].push_back(towers[i].front());
            towers[i].pop_front();
        }
    }
    cout << ans << "\n";
    for (const auto& a : seq) {
        cout << a.first << " " << a.second << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
