#include <bits/stdc++.h>
using namespace std;

int n { 0 };

vector<int> search(const int& root, const vector<vector<int>>& tree) {
    stack<int> st;
    st.push(root);
    vector<int> parentOf (n);
    parentOf[root] = -1;
    vector<int> dist (n);
    dist[root] = 0;
    while (!st.empty()) {
        int t { st.top() }; 
        st.pop();
        if (t != root) { dist[t] = dist[parentOf[t]]+1; }
        for (const int& a : tree[t]) {
            if (a != parentOf[t]) {
                st.push(a);
                parentOf[a] = t;
            }
        }
    }
    return dist;
}

void solve() {
    cin >> n;
    vector<vector<int>> tree (n);
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a-1].push_back(b-1);
        tree[b-1].push_back(a-1);
    }
    vector<int> dist { search(0, tree) };
    int maxDist { 0 };
    int newRoot { 0 };
    for (int i = 0; i < n; i++) {
        if (dist[i] > maxDist) {
            maxDist = dist[i];
            newRoot = i;
        }
    }
    vector<int> dist2 { search(newRoot, tree) };
    cout << *max_element(dist2.begin(), dist2.end()) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
