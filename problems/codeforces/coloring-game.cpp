#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n { 0 }; 
    int m { 0 };
    cin >> n >> m;
    vector<vector<int>> adj (n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    vector<bool> black (n); 
    vector<bool> vis (n);
    bool possible { true };
    queue<int> col1;
    queue<int> col2;
    for (int i = 0; i < n; i++) {
        if (vis[i]) { continue; }
        stack<int> s;
        s.push(i);
        vis[i] = true;
        black[i] = true;
        col1.push(i);
        while (!s.empty()) {
            int t { s.top() }; 
            s.pop();
            for (const int& a : adj[t]) {
                if (vis[a]) {
                    if (black[a] == black[t]) { possible = false; break; }
                    else { continue; }
                }
                s.push(a);
                vis[a] = true;
                black[a] = !black[t];
                if (black[a]) { col1.push(a); }
                else { col2.push(a); }
            }
        }
        if (!possible) { break; }
    }
    if (possible) {
        cout << "Bob" << "\n";
        cout.flush();
        for (int i = 0; i < n; i++) {
            int t1, t2;
            cin >> t1 >> t2;
            int c1 { min(t1, t2) }; 
            int c2 { max(t1, t2) }; 
            if (c1 == 1) {
                if (col1.empty()) {
                    cout << col2.front()+1 << " " << c2 << "\n";
                    cout.flush();
                    col2.pop();
                }
                else {
                    cout << col1.front()+1 << " " << c1 << "\n";
                    cout.flush();
                    col1.pop();
                }
            }
            else if (c1 == 2) {
                if (col2.empty()) {
                    cout << col1.front()+1 << " " << c2 << "\n";
                    cout.flush();
                    col1.pop();
                }
                else {
                    cout << col2.front()+1 << " " << c1 << "\n";
                    cout.flush();
                    col2.pop();
                }
            }
        }
    }
    else {
        cout << "Alice" << "\n";
        cout.flush();
        for (int i = 0; i < n; i++) {
            cout << 1 << " " << 2 << "\n";
            cout.flush();
            int t { 0 };
            cin >> t >> t;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t { 0 };
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}
