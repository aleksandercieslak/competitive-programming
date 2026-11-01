#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n { 0 };
    int m { 0 };
    cin >> n >> m;
    vector<vector<char>> grid (n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    int answer { 0 };
    vector<vector<bool>> vis (n, vector<bool>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j] || grid[i][j] == '#') { continue; }
            stack<pair<int, int>> s;
            s.push({i, j});
            vis[i][j] = true;
            answer++;
            while (!s.empty()) {
                int r { s.top().first }; 
                int c { s.top().second }; 
                s.pop();
                if (r != 0 && !vis[r-1][c] && grid[r-1][c] == '.') { s.push({r-1, c}); vis[r-1][c] = true; } 
                if (r != n-1 && !vis[r+1][c] && grid[r+1][c] == '.') { s.push({r+1, c}); vis[r+1][c] = true; } 
                if (c != 0 && !vis[r][c-1] && grid[r][c-1] == '.') { s.push({r, c-1}); vis[r][c-1] = true; } 
                if (c != m-1 && !vis[r][c+1] && grid[r][c+1] == '.') { s.push({r, c+1}); vis[r][c+1] = true; } 
            }
        }
    }
    cout << answer << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
