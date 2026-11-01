#include <bits/stdc++.h>
using namespace std;

vector<int> heightBound(int numberOfCows, int division, vector<pair<int, int>> cows) {
    int total { 0 };
    vector<int> counter (numberOfCows);
    vector<int> bound (numberOfCows);
    int totalBound { numberOfCows-1 };
    int i { 0 };
    for (int x = 0; x < numberOfCows; x++) {
        while (i < numberOfCows && cows[i].first == x) {
            counter[cows[i].second]++;
            if (cows[i].second <= totalBound) {
                total++;
            }
            i++;
        }
        while (total > division) {
            total -= counter[totalBound];
            totalBound--;
        }
        bound[x] = totalBound;
    }
    return bound;
}

void solve() {
    int numberOfCows { 0 };
    cin >> numberOfCows;
    vector<pair<int, int>> cows (numberOfCows);
    for (int i = 0; i < numberOfCows; i++) {
        cin >> cows[i].first >> cows[i].second;
    }
    sort(cows.begin(), cows.end());
    int newIndex { 0 };
    int oldIndex { cows[0].first };
    for (int i = 0; i < numberOfCows; i++) {
        if (oldIndex != cows[i].first) {
            newIndex++;
        }
        oldIndex = cows[i].first;
        cows[i].first = newIndex;
    }
    sort(cows.begin(), cows.end(), [](pair<int, int> a, pair<int, int> b) { 
        if (a.second != b.second) {
            return a.second < b.second;
        }
        else {
            return a.first < b.first;
        }
    });
    newIndex = 0;
    oldIndex = cows[0].second;
    for (int i = 0; i < numberOfCows; i++) {
        if (oldIndex != cows[i].second) {
            newIndex++;
        }
        oldIndex = cows[i].second;
        cows[i].second = newIndex;
    }
    int left { 1 };
    sort(cows.begin(), cows.end());
    int right { numberOfCows+1 };
    while (left < right) {
        int middle { (left+right)/2 };
        bool isPossible { false };
        vector<int> bottomLeft = heightBound(numberOfCows, middle, cows);
        for (int i = 0; i < numberOfCows; i++) { cows[i].first = numberOfCows-1-cows[i].first; }
        reverse(cows.begin(), cows.end());
        vector<int> bottomRight = heightBound(numberOfCows, middle, cows);
        for (int i = 0; i < numberOfCows; i++) { cows[i].second = numberOfCows-1-cows[i].second; }
        vector<int> topRight = heightBound(numberOfCows, middle, cows);
        for (int i = 0; i < numberOfCows; i++) { cows[i].first = numberOfCows-1-cows[i].first; }
        reverse(cows.begin(), cows.end());
        vector<int> topLeft = heightBound(numberOfCows, middle, cows);
        for (int x = 0; x < numberOfCows-1; x++) {
            if (min(bottomLeft[x], bottomRight[numberOfCows-2-x])+1+min(topLeft[x], topRight[numberOfCows-2-x])+1 >= numberOfCows) {
                isPossible = true;
                break;
            }
        }
        if (isPossible) {
            right = middle;
        }
        else {
            left = middle+1;
        }
    }
    cout << left << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}