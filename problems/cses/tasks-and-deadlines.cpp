#include <bits/stdc++.h>
using namespace std;

void solve() {
    int numberOfTasks { 0 };
    cin >> numberOfTasks;
    vector<pair<int, int>> tasks (numberOfTasks);
    for (auto& a : tasks) {
        cin >> a.first >> a.second;
    }
    sort(tasks.begin(), tasks.end());
    int answer { 0 };
    int time { 0 };
    for (const auto& a : tasks) {
        time += a.first;
        answer += a.second-time;
    }
    cout << answer << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}