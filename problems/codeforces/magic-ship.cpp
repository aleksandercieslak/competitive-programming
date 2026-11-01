#include <bits/stdc++.h>
using namespace std;

bool isPossible(pair<int, int> position, int x2, int y2, int days) {
    if (abs(x2-position.first)+abs(y2-position.second) > days) {
        return false;
    }
    return true;
}

void solve() {
    int x1, y1, x2, y2;
    int length { 0 };
    string forecast;
    cin >> x1 >> y1 >> x2 >> y2 >> length >> forecast;
    vector<pair<int, int>> change (length+1);
    change[0].first = 0;
    change[0].second = 0;
    for (int i = 1; i <= length; i++) {
        change[i] = change[i-1];
        if (forecast[i-1] == 'U') { change[i].second++; }
        else if (forecast[i-1] == 'D') { change[i].second--; }
        else if (forecast[i-1] == 'L') { change[i].first--; }
        else if (forecast[i-1] == 'R') { change[i].first++; }
    }
    int left { 1 };
    int right { 100000000 };
    while (left < right) {
        int middle { (left+right)/2 };
        pair<int, int> position = {x1, y1};
        int multip { middle/length };
        int mod { middle%length };
        position.first += change[length].first * multip;
        position.first += change[mod].first;
        position.second += change[length].second * multip;
        position.second += change[mod].second;
        if (isPossible(position, x2, y2, middle)) {
            right = middle;
        }
        else {
            left = middle+1;
        }
    }
    pair<int, int> temp = {x1, y1};
    int multip { left/length };
    int mod { left%length };
    temp.first += change[length].first * multip;
    temp.first += change[mod].first;
    temp.second += change[length].second * multip;
    temp.second += change[mod].second;
    if (isPossible(temp, x2, y2, left)) {
        cout << left << "\n";
    }
    else {
        cout << -1 << "\n";
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}