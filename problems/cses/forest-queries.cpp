#include <bits/stdc++.h>
using namespace std;

void solve() {
    int forestSize { 0 };
    int numberOfQueries { 0 };
    cin >> forestSize >> numberOfQueries;
    vector<vector<int>> forest (forestSize+1);
    for (int i = 0; i <= forestSize; i++) {
        forest[0].push_back(0);
    }
    for (int i = 1; i <= forestSize; i++) {
        string temp;
        cin >> temp;
        forest[i].push_back(0);
        for (int j = 0; j < forestSize; j++) {
            if (temp[j] == '.') {
                forest[i].push_back(0);
            }
            else {
                forest[i].push_back(1);
            }
        }
    }
    vector<vector<int>> prefix (forestSize+1, vector<int>(forestSize+1));
    for (int i = 1; i <= forestSize; i++) {
        for (int j = 1; j <= forestSize; j++) {
            prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + forest[i][j];
        }
    }
    for (int q = 0; q < numberOfQueries; q++) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        cout << prefix[y2][x2] - prefix[y1-1][x2] - prefix[y2][x1-1] + prefix[y1-1][x1-1] << "\n";
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}