#include <bits/stdc++.h>
using namespace std;

void solve() {
    int side { 0 };
    cin >> side;
    vector<vector<int>> value (side, vector<int>(side));
    for (int i = 0; i < side; i++) {
        for (int j = 0; j < side; j++) {
            cin >> value[i][j];
        }
    }
    int maxColumn { 0 };
    int maxRow { 0 };
    for (int i = 0; i < side; i++) {
        vector<int> sum (2);
        for (int j = 0; j < side; j++) {
            sum[j%2] += value[i][j];
        }
        maxRow += max(sum[0], sum[1]);
    }
    for (int i = 0; i < side; i++) {
        vector<int> sum (2);
        for (int j = 0; j < side; j++) {
            sum[j%2] += value[j][i];
        }
        maxColumn += max(sum[0], sum[1]);
    }

    cout << max(maxRow, maxColumn) << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}