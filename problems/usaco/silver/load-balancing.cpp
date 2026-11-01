#include <bits/stdc++.h>
using namespace std;

void solve() {
    int numberOfCows { 0 };
    int maxPosition { 0 };
    cin >> numberOfCows >> maxPosition;
    vector<pair<int, int>> position (numberOfCows);
    vector<int> x (numberOfCows);
    vector<int> y (numberOfCows);
    for (int i = 0; i < numberOfCows; i++) {
        cin >> x[i] >> y[i];
    }
    int answer { 100 };
    int topLeft { 0 };
    int topRight { 0 };
    int bottomLeft { 0 };
    int bottomRight { 0 };
    int minX = *min_element(x.begin(), x.end());
    int minY = *min_element(y.begin(), y.end());
    int maxX = *max_element(x.begin(), x.end());
    int maxY = *max_element(y.begin(), y.end());
    for (int i = minX - 1; i <= maxX + 1; i += 2) {
        for (int j = minY - 1; j <= maxY + 1; j += 2) {
            for (int k = 0; k < numberOfCows; k++) {
                if (x[k] > i && y[k] > j) {
                    topRight++;
                }
                if (x[k] > i && y[k] < j) {
                    bottomRight++;
                }
                if (x[k] < i && y[k] > j) {
                    topLeft++;
                }
                if (x[k] < i && y[k] < j) {
                    bottomLeft++;
                }
            }
            int projection = max(max(topRight, bottomRight), max(topLeft, bottomLeft));
            answer = min(answer, projection);
            topRight = 0;
            bottomRight = 0;
            topLeft = 0;
            bottomLeft = 0;
        }
    }
    cout << answer << "\n";    
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}