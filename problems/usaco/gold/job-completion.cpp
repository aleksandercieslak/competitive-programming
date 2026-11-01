#include <bits/stdc++.h>
using namespace std;

void solve() {
    int numberOfJobs { 0 };
    cin >> numberOfJobs;
    vector<pair<int, int>> jobs (numberOfJobs);
    for (auto& a : jobs) {
        cin >> a.first >> a.second;
    }
    sort(jobs.begin(), jobs.end());
    int answer { 1 };
    int current { jobs.back().first };
    priority_queue<int, vector<int>, greater<int>> pq;
    while (current > 0) {
        while (!jobs.empty() && jobs.back().first + jobs.back().second > current) {
            pq.push(jobs.back().second);
            jobs.pop_back();
        }
        while (!pq.empty() && pq.top() > current) {
            pq.pop();
        }
        if (!pq.empty() && (jobs.empty() || pq.top() < current-jobs.back().first)) {
            current -= pq.top();
            pq.pop();
            answer++;
        }
        else if (!jobs.empty() && (pq.empty() || current-jobs.back().first >= pq.top())) {
            current = jobs.back().first;
            jobs.pop_back();
            answer++;
        }
        else {
            break;
        }
    }
    cout << answer << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tests { 0 };
    cin >> tests;
    for (int i = 0; i < tests; i++) {
        solve();
    }
    return 0;
}
