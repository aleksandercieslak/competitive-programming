#include <bits/stdc++.h>
using namespace std;

void solve() {
    int minutes { 0 };
    int numberOfSushi { 0 };
    cin >> minutes >> numberOfSushi;
    deque<int> deliciousness (minutes);
    for (int& a : deliciousness) {
        cin >> a;
    }
    int total { minutes/(numberOfSushi+1) };
    long long answer { 0 };
    int m { 1 };
    priority_queue<int> pq;
    while (total > 0) {
        pq.push(deliciousness.front());
        deliciousness.pop_front();
        if (m == minutes+1-total*(numberOfSushi+1)) {
            answer += pq.top(); 
            pq.pop();
            total--;
        } 
        m++;
    }
    cout << answer << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tests { 0 };
    cin >> tests;
    for (int q = 0; q < tests; q++) {
        solve();
    }
    return 0;
}
