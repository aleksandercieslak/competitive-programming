#include <bits/stdc++.h>
using namespace std;

void solve() {
    int numberOfChildern { 0 };
    int maxWeight { 0 };
    cin >> numberOfChildern >> maxWeight;
    deque<int> children (numberOfChildern);
    for (int& a : children) {
        cin >> a;
    }
    sort(children.begin(), children.end());
    int answer { 0 };
    while (static_cast<int>(children.size()) > 1) {
        if (children.front() + children.back() <= maxWeight) {
            children.pop_front();
            children.pop_back();
            answer++;
        }
        else {
            children.pop_back();
            answer++;
        }
    }
    if (static_cast<int>(children.size()) == 1) {
        answer++;
    }
    cout << answer << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
