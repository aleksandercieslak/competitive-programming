#include <bits/stdc++.h>
using namespace std;

void solve() {
    int numberOfAlgorithms { 0 };
    int numberOfMinutes { 0 };
    cin >> numberOfAlgorithms >> numberOfMinutes;
    vector<int> algorithms (numberOfAlgorithms);
    for (int& a : algorithms) {
        cin >> a;
    }
    sort(algorithms.begin(), algorithms.end());
    int answer { 0 };
    for (const auto& a : algorithms) {
        numberOfMinutes -= a;
        if (numberOfMinutes < 0) { break; }
        answer++;
    }
    cout << answer << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}