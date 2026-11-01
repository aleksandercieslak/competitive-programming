#include <bits/stdc++.h>
using namespace std;

void search(vector<bool>& column, vector<bool>& firstDiagonal, vector<bool>& secondDiagonal, int k, int& counter, const vector<vector<char>>& board) {
    if (k == 8) {
        counter++;
    }
    else {
        for (int i = 0; i < 8; i++) {
            if (column[i] || firstDiagonal[i+k] || secondDiagonal[i-k+7] || board[k][i] == '*') { continue; }
            else {
                column[i] = firstDiagonal[i+k] = secondDiagonal[i-k+7] = 1;
                search(column, firstDiagonal, secondDiagonal, k+1, counter, board);
                column[i] = firstDiagonal[i+k] = secondDiagonal[i-k+7] = 0;
            }
        }
    }
}


void solve() {
    vector<vector<char>> board (8, vector<char> (8));
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> board[i][j];
        }
    }
    int counter { 0 };
    vector<bool> column (8, false);
    vector<bool> firstDiagonal (15, false);
    vector<bool> secondDiagonal (15, false);
    search(column, firstDiagonal, secondDiagonal, 0, counter, board);
    cout << counter << "\n";

}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}