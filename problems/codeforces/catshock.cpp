#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n { 0 };
    cin >> n;
    vector<vector<int>> adj (n);
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    int maxDistance { 0 };
    vector<bool> vis (n);
    queue<int> bq;
    bq.push(0);
    vis[0] = true;
    vector<vector<int>> distance (n);
    vector<int> ds (n);
    distance[0].push_back(0);
    ds[0] = 0;
    int k { 0 };
    while (!bq.empty()) {
        int t { bq.front() }; 
        bq.pop();
        k = ds[t]+1;
        for (const int& a : adj[t]) {
            if (vis[a]) { continue; }
            bq.push(a);
            vis[a] = true;
            distance[k].push_back(a);
            ds[a] = k;
            maxDistance = max(maxDistance, k);
        } 
    }
    for (int i = 0; i < n; i++) {
        vis[i] = false;
    }
    vector<bool> onPath (n);
    stack<int> dStack;
    dStack.push(0);
    vis[0] = true;
    vector<int> optimal (n);
    optimal[0] = 0;
    while (!dStack.empty()) {
        int t { dStack.top() }; 
        dStack.pop();
        optimal[ds[t]] = t;
        if (t == n-1) { break; }
        for (const int& a : adj[t]) {
            if (vis[a]) { continue; }
            dStack.push(a);
            vis[a] = true;
        }
    }
    queue<int> final;
    final.push(0);
    for (int i = 1; i < n; i++) {
        if (optimal[i] != 0) {
            onPath[optimal[i]] = true;
            final.push(optimal[i]);
        } 
    }
    onPath[0] = true;
    vector<pair<int, int>> operations;  
    bool arePaths { true };
    bool even { true };
    bool can { true };
    int furthest { maxDistance };
    while (arePaths) {
        while (!distance[furthest].empty() && onPath[distance[furthest].back()]) {
            distance[furthest].pop_back(); 
            while (distance[furthest].empty() && furthest > 0) {
                furthest--;
            }
        }
        if (can && furthest%2 == even) {
            operations.push_back({2, distance[furthest].back()+1});
            distance[furthest].pop_back(); 
            can = false;
            while (distance[furthest].empty() && furthest > 0) {
                furthest--; 
            }
        }
        else {
            even = !even;
            can = true;
            operations.push_back({1, 0});
        }
        if (distance[0].empty()) {
            arePaths = false;
        }
    }
    while (final.size() > 1) {
        if (can && ds[final.front()]%2 == even) {
            operations.push_back({2, final.front()+1}); 
            final.pop();
        }  
        else {
            even = !even;
            can = true;
            operations.push_back({1, 0});
        }
    }
    cout << operations.size() << "\n";
    for (const auto& a : operations) {
        if (a.first == 1) { cout << a.first << "\n"; }
        else { cout << a.first << " " << a.second << "\n"; }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q { 0 };
    cin >> q;
    for (int i = 0; i < q; i++) {
        solve();
    }
    return 0;
}
