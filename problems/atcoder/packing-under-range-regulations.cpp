#include <bits/stdc++.h>
using namespace std;

void solve() {
    int numberOfBalls { 0 };
    cin >> numberOfBalls;
    deque<pair<int, int>> balls (numberOfBalls);
    for (auto& a : balls) {
        cin >> a.first >> a.second;
    }
    sort(balls.begin(), balls.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    bool possible { true };
    for (int i = 1; i <= 1000000000; i++) {
        if (!pq.empty() && pq.top() < i) {
            possible = false;
            break;
        }
        while (!balls.empty() && balls[0].first == i) {
            pq.push(balls[0].second);
            balls.pop_front();
        } 
        if (pq.empty()) {
            if (balls.empty()) {
                break;
            }
            else {
                i = balls[0].first; 
            }
        }
        else {
            pq.pop();
        }
    }
    if (possible) {
        cout << "Yes" << "\n";
    }
    else {
        cout << "No" << "\n";
    }
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
