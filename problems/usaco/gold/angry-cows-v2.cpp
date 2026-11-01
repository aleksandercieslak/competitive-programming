#include <bits/stdc++.h>
using namespace std;

bool isPossible(const vector<int>& haybales, int radius, int position, char direction) {
    if (direction == 'L') {
        int ogPosition { position };
        if (haybales[upper_bound(haybales.begin(), haybales.end(), position) - haybales.begin() - 1] < position - radius) { return false; }
        else {
            position = upper_bound(haybales.begin(), haybales.end(), position) - haybales.begin() - 1;
            while (haybales[position-1] >= haybales[ogPosition]-radius) {
                position--;
            }
            radius -= 2;
        }
        while (position > 0) {
            int index { position };
            while (haybales[index-1] >= haybales[position]-radius) {
                index--;
                if (index == 0) { break; }
            }
            if (index == position) { return false; }
            position = index;
            radius -= 2;
            if (position == 0) { return true; }
            if (radius <= 0) { return false; }
        }
    }
    else {
        int ogPosition { position };
        if (haybales[lower_bound(haybales.begin(), haybales.end(), position) - haybales.begin()] > position + radius) { return false; }
        else {
            position = lower_bound(haybales.begin(), haybales.end(), position) - haybales.begin();
            while (haybales[position+1] <= haybales[ogPosition]+radius) {
                position++;
            }
            radius -= 2;
        }
        int size { static_cast<int>(haybales.size()) };
        while (position < size-1) {
            int index { position };
            while (haybales[index+1] <= haybales[position]+radius) {
                index++;
                if (index == size-1) { break; }
            }
            if (index == position) { return false; }
            position = index;
            radius -= 2;
            if (position == size-1) { return true; }
            if (radius <= 0) { return false; }
        }
    }
    return true;
}

void solve() {
    int numberOfHaybales { 0 };
    cin >> numberOfHaybales;
    vector<int> haybales (numberOfHaybales);
    for (int i = 0; i < numberOfHaybales; i++) {
        cin >> haybales[i];
    }
    int haybalesSize { static_cast<int>(haybales.size()) };
    sort(haybales.begin(), haybales.end());
    for (int i = 0; i < haybalesSize; i++) {
        haybales[i] *= 2;
    }
    int biggest { *max_element(haybales.begin(), haybales.end()) };
    int smallest { *min_element(haybales.begin(), haybales.end()) };
    int leftR { smallest };
    int rightR { biggest };
    int answer { rightR };
    while (leftR <= rightR) {
        int middleR { (leftR+rightR)/2 };
        int leftPos { smallest };
        int rightPos { biggest };
        bool radiusIsValid { false };
        while (leftPos <= rightPos) {
            int middlePos { (leftPos+rightPos)/2 };
            if (isPossible(haybales, middleR, middlePos, 'L')) {
                leftPos = middlePos+1;
            }
            else {
                rightPos = middlePos-1;
            }
        }
        int bestPos { leftPos-1 };
        if (bestPos >= 0 && isPossible(haybales, middleR, bestPos, 'L') && isPossible(haybales, middleR, bestPos, 'R')) { radiusIsValid = true; }
        if (radiusIsValid) {
            answer = min(answer, middleR);
            rightR = middleR-1;
        }
        else {
            leftR = middleR+1;
        }
    }
    cout << fixed << setprecision(1) << static_cast<double>(answer)/2 << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}