#include <bits/stdc++.h>
using namespace std;

void solve() {
    int numberOfOpponents { 0 };
    int time { 0 };
    cin >> numberOfOpponents >> time;
    vector<int> oppontents (numberOfOpponents);
    for (int& a : oppontents) {
        cin >> a;
    }
    vector<pair<int, int>> sorted (numberOfOpponents);
    for (int i = 0; i < numberOfOpponents; i++) {
        sorted[i].first = oppontents[i];
        sorted[i].second = i;
    } 
    sort(sorted.begin(), sorted.end());
    int wins { 0 };
    int biggestCost { 0 };
    vector<bool> beaten (numberOfOpponents);
    for (int i = 0; i < numberOfOpponents; i++) {
        if (time >= sorted[i].first) {
            time -= sorted[i].first;
            wins++;
            biggestCost = sorted[i].first;
            beaten[sorted[i].second] = true;
        }
        else {
            break;
        }
    }
    vector<int> victories (numberOfOpponents);
    if (wins < numberOfOpponents && time + biggestCost >= oppontents[wins] && !beaten[wins]) {
        victories[wins]--;
        victories[sorted[wins-1].second]++;
    }
    for (int i = 0; i < wins; i++) {
        victories[sorted[i].second]--;
    }
    for (int i = 0; i < numberOfOpponents; i++) {
        victories[i] += i+1;
    }
    int answer { 0 };
    for (int i = numberOfOpponents-1; i >= 0; i--) {
        if (victories[i] > wins) {
            answer++;
        }
        else {
            break;
        }
    }
    cout << answer+1 << "\n";
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
