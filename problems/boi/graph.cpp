#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n { 0 };
    int m { 0 };
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj (n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a-1].push_back({c, b-1});
        adj[b-1].push_back({c, a-1});
    }
    vector<bool> visited (n);
    vector<int> sign (n); 
    vector<int> add (n);
    vector<double> val (n);
    bool possible { true };
    for (int i = 0; i < n; i++) {
        if (visited[i]) { continue; }
        vector<int> con;
        visited[i] = true;
        stack<int> dfsStack;
        dfsStack.push(i);
        con.push_back(i);
        sign[i] = 1;
        add[i] = 0;
        bool sf { false };
        double s { 0 };
        while (!dfsStack.empty()) {
            int t { dfsStack.top() }; 
            dfsStack.pop();
            for (const auto& a : adj[t]) {
                if (visited[a.second]) {
                    if (sign[a.second] != sign[t]) {
                        if (add[a.second] + add[t] != a.first) {
                            possible = false;
                        }
                    } 
                    else {
                        double f { (static_cast<double>(a.first-add[a.second]-add[t]))/(sign[a.second]+sign[t]) };
                        if (sf && s != f) { possible = false; }
                        else {
                            sf = true;
                            s = f;
                        }
                    }
                    continue;
                }
                sign[a.second] = -1 * sign[t]; 
                add[a.second] = a.first - add[t];
                dfsStack.push(a.second);
                visited[a.second] = true;
                con.push_back(a.second);
            }
        }
        for (int& a : con) {
            if (sign[a] == -1) {
                a = add[a];
            }
            else {
                a = -1 * add[a];
            }
        }  
        nth_element(con.begin(), con.begin() + con.size()/2, con.end());
        int v { con[con.size()/2] };
        if (sf) {
            val[i] = s;
        }
        else {
            val[i] = v;
        }
    }
    if (!possible) { cout << "NO" << "\n"; }
    else {
        vector<bool> vis (n); 
        for (int i = 0; i < n; i++) {
            if (vis[i]) { continue; }
            vis[i] = true;
            stack<int> st;
            st.push(i);
            while (!st.empty()) {
                int tp { st.top() }; 
                st.pop();
                for (const auto& a : adj[tp]) {
                    if (vis[a.second]) { continue; }
                    st.push(a.second);
                    vis[a.second] = true;
                    val[a.second] = a.first-val[tp];
                }
            }
        }
        cout << "YES" << "\n";
        for (int i = 0; i < n; i++) {
            if (i < n-1) {
                cout << val[i] << " ";
            }
            else {
                cout << val[i] << "\n";
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
