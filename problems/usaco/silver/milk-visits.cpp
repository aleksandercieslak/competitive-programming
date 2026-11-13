#include <bits/stdc++.h>
using namespace std;

int n { 0 };
int m { 0 };
vector<int> parentOf;
vector<int> branch;

vector<int> traversal (const vector<vector<int>>& con) {
    vector<int> order; 
    stack<int> st;
    st.push(0);
    parentOf[0] = -1;
    branch[0] = -1;
    int ind { -1 };
    while (!st.empty()) {
        int t { st.top() }; 
        st.pop();
        order.push_back(t);
        if (parentOf[t] == 0) { ind++; branch[t] = ind; }
        for (const int& a : con[t]) {
            if (a != parentOf[t]) {
                st.push(a);
                parentOf[a] = t;
                branch[a] = ind;
            }
        }
    }
    return order;
}

void solve() {
    cin >> n >> m;
    parentOf.resize(n);
    branch.resize(n);
    string breed;
    cin >> breed;
    vector<vector<int>> con (n);
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        con[a-1].push_back(b-1);
        con[b-1].push_back(a-1);
    }
    vector<int> order { traversal(con) };
    reverse(order.begin(), order.end());
    vector<pair<int, int>> counter (n);  
    for (int i = 0; i < n; i++) {
        if (parentOf[order.back()] != -1) {
            counter[order.back()] = counter[parentOf[order.back()]]; 
        }
        if (breed[order.back()] == 'G') { counter[order.back()].first++; } 
        else { counter[order.back()].second++; };
        order.pop_back();
    } 
    string ans;
    for (int i = 0; i < m; i++) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        if ((branch[a-1] == branch[b-1] && c == 'G' && counter[a-1].first != counter[b-1].first)
            || (branch[a-1] != branch[b-1] && c == 'G' && (counter[a-1].first > 0 || counter[b-1].first > 0))) 
                { ans.push_back('1'); }
        else if ((branch[a-1] == branch[b-1] && c == 'H' && counter[a-1].second != counter[b-1].second)
            || (branch[a-1] != branch[b-1] && c == 'H' && (counter[a-1].second > 0 || counter[b-1].second > 0))) 
                { ans.push_back('1'); }
        else { ans.push_back('0'); }
    } 
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
