#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n { 0 };
    cin >> n;
    vector<vector<int>> subordinates (n);
    vector<int> parent (n);
    parent[0] = -1;
    for (int i = 0; i < n-1; i++) {
        int t;
        cin >> t;
        subordinates[t-1].push_back(i+1);
        parent[i+1] = t-1;
    }
    vector<int> order;
    stack<int> st;    
    st.push(0);
    order.push_back(0);
    while (!st.empty()) {
        int t { st.top() }; 
        st.pop();
        for (const int& a : subordinates[t]) {
            st.push(a);
            order.push_back(a);
        }
    }
    vector<int> ans (n);
    for (int i = n-1; i >= 0; i--) {
        if (parent[order[i]] != -1) {
            ans[parent[order[i]]] += ans[order[i]] + 1;
        }
    }
    for (const int& a : ans) {
        cout << a << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
