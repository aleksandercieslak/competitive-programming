#include <bits/stdc++.h>
using namespace std;

void solve() {
    int numberOfRows { 0 };
    int numberOfColumns { 0 };
    int numberOfQueries { 0 };
    cin >> numberOfRows >> numberOfColumns >> numberOfQueries;
    vector<vector<int>> grid (numberOfRows+1);
    for (int i = 0; i <= numberOfColumns; i++) {
        grid[0].push_back(0);
    }
    for (int i = 1; i <= numberOfRows; i++) {
        string temp;
        cin >> temp;
        grid[i].push_back(0);
        for (int j = 0; j < numberOfColumns; j++) {
            grid[i].push_back(temp[j]-'0');
        }
    }
    vector<vector<int>> prefix (numberOfRows+1, vector<int>(numberOfColumns+1));
    for (int i = 1; i <= numberOfRows; i++) {
        for (int j = 1; j <= numberOfColumns; j++) {
            if (grid[i][j] == 0) {
                prefix[i][j] = prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1];
            }
            else if (grid[i][j] == 1) {
                if (grid[i-1][j] == 0 && grid[i][j-1] == 0) {
                    prefix[i][j] = prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1]+1;
                }
                else if (grid[i-1][j] == 1 && grid[i][j-1] == 1) {
                    prefix[i][j] = prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1]-1;
                }
                else {
                    prefix[i][j] = prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1];
                }
            }
        }
    }
    vector<vector<int>> horizontalPrefix (numberOfRows+1, vector<int>(numberOfColumns+1));
    vector<vector<int>> verticalPrefix (numberOfRows+1, vector<int>(numberOfColumns+1));
    for (int i = 1; i <= numberOfRows; i++) {
        for (int j = 1; j <= numberOfColumns; j++) {
            horizontalPrefix[i][j] = horizontalPrefix[i][j-1];
            verticalPrefix[i][j] = verticalPrefix[i-1][j];
            if (grid[i][j] == 1) {
                horizontalPrefix[i][j] += (grid[i][j-1] == 0);
                verticalPrefix[i][j] += (grid[i-1][j] == 0);
            }
        }
    }
    for (int q = 0; q < numberOfQueries; q++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int answer { 0 };
        answer += grid[x1][y1];
        answer += horizontalPrefix[x1][y2] - horizontalPrefix[x1][y1];
        answer += verticalPrefix[x2][y1] - verticalPrefix[x1][y1];
        answer += prefix[x2][y2] - prefix[x1][y2] - prefix[x2][y1] + prefix[x1][y1];
        cout << answer << "\n";
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}