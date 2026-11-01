#include <bits/stdc++.h>
using namespace std;

void solve() {
    int side { 0 };
    cin >> side;
    vector<vector<int>> canvas (side, vector<int>(side));
    for (int i = 0; i < side; i++) {
        for (int j = 0; j < side; j++) {
            cin >> canvas[i][j];
        }
    }
    struct Info {
        int top { 1000 };
        int bottom { 0 };
        int left { 1000 };
        int right = { 0 };
        
    };
    unordered_map<int, Info> sides;
    for (int i = 0; i < side; i++) {
        for (int j = 0; j < side; j++) {
            int cell { canvas[i][j] };
            sides[cell].top = min(i, sides[cell].top);
            sides[cell].bottom = max(i, sides[cell].bottom);
            sides[cell].left = min(j, sides[cell].left);
            sides[cell].right = max(j, sides[cell].right);
        }
    }
    int potentialFirst { side*side };
    for (auto a : sides) {
        if (a.first == 0) { continue; }
        int t { a.second.top };
        int b { a.second.bottom };
        int l { a.second.left };
        int r { a.second.right };
        if (b < side-1 && l > 0) {
            if (canvas[b+1][l] == canvas[b][l-1] && canvas[b][l-1] == canvas[b+1][l-1] && canvas[b+1][l-1] != 0) {
                potentialFirst--;
                continue;
            }
        }
        if (t > 0 && l > 0) {
            if (canvas[t-1][l] == canvas[t][l-1] && canvas[t][l-1] == canvas[t-1][l-1] && canvas[t-1][l-1] != 0) {
                potentialFirst--;
                continue;
            }
        }
        if (b < side-1 && r < side-1) {
            if (canvas[b+1][r] == canvas[b][r+1] && canvas[b][r+1] == canvas[b+1][r+1] && canvas[b+1][r+1] != 0) {
                potentialFirst--;
                continue;
            }
        }
        if (t > 0 && r < side-1) {
            if (canvas[t-1][r] == canvas[t][r+1] && canvas[t][r+1] == canvas[t-1][r+1] && canvas[t-1][r+1] != 0) {
                potentialFirst--;
                continue;
            }
        }
    }
    cout << potentialFirst << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}