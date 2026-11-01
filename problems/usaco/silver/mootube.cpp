#include <bits/stdc++.h>
using namespace std;

int n { 0 };

int sug(const vector<vector<pair<int, int>>>& vids, int root, int k) {
    vector<int> parentOf (n); 
    stack<int> st;
    st.push(root);
    parentOf[root] = -1;
    int counter { 0 };
    while (!st.empty()) {
        int t { st.top() }; 
        st.pop();
        for (const auto& a : vids[t]) {
            if (a.first == parentOf[t] || a.second < k) { continue; }
            st.push(a.first);
            parentOf[a.first] = t;
            counter++;
        }
    }
    return counter;
}

void solve() {
    int q { 0 };
    cin >> n >> q;
    vector<vector<pair<int, int>>> vids (n);
    for (int i = 0; i < n-1; i++) {
        int a, b, r;
        cin >> a >> b >> r;
        vids[a-1].push_back({b-1, r});
        vids[b-1].push_back({a-1, r});
    }
    for (int i = 0; i < q; i++) {
        int k, v;
        cin >> k >> v;
        cout << sug(vids, v-1, k) << "\n"; 
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
