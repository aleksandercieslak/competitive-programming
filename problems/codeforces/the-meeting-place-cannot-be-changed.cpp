#include <bits/stdc++.h>
using namespace std;

bool leftHasMax { false };
bool rightHasMax { false };

double minTime(vector<int> position, vector<int> speed, double destination) {
    double maxTime { 0 };
    for (int i = 0; i < static_cast<int>(position.size()); i++) {
        double time { static_cast<double>(abs(destination-position[i]))/speed[i] };
        if (time > maxTime) {
            leftHasMax = false;
            rightHasMax = false;
            if (position[i] > destination) {
                rightHasMax = true;
            }
            else {
                leftHasMax = true;
            }
            maxTime = time;
        }
        else if (time == maxTime) {
            if (position[i] > destination) {
                rightHasMax = true;
            }
            else {
                leftHasMax = true;
            }
        }
    }
    return maxTime;
}

void solve() {
    int numberOfFriends { 0 };
    cin >> numberOfFriends;
    vector<int> position (numberOfFriends);
    for (int i = 0; i < numberOfFriends; i++) {
        cin >> position[i];
    }
    vector<int> speed (numberOfFriends);
    for (int i = 0; i < numberOfFriends; i++) {
        cin >> speed[i];
    }
    double left { static_cast<double>(*min_element(position.begin(), position.end())) };
    double right { static_cast<double>(*max_element(position.begin(), position.end())) };
    double best { right };
    while (right-left > 0.000001) {
        double middle { (left+right)/2 };
        best = min(best, minTime(position, speed, middle));
        if (leftHasMax && rightHasMax) { break; }
        else if (leftHasMax) { right = middle; }
        else { left = middle; }
    }
    cout << fixed << best << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}