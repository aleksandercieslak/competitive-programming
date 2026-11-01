#include <bits/stdc++.h>
using namespace std;

void solve() {
    int stickLength { 0 };
    int numberOfSticks { 0 };
    cin >> stickLength >> numberOfSticks;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < numberOfSticks; i++) {
        int a;
        cin >> a;
        pq.push(a);
    }
    int answer { 0 };
    while (pq.size() > 1) {
        int a { pq.top() };
        pq.pop();
        int b { pq.top() };
        pq.pop();
        pq.push(a+b);
        answer += a+b;
    }
    cout << answer << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
