#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n { 0 };
    int m { 0 };
    cin >> n >> m;
    vector<unordered_set<int>> noEdge (n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        noEdge[a].insert(b);
        noEdge[b].insert(a);
    }
    set<int> unvisited;
    for (int i = 0; i < n; i++) {
        unvisited.insert(i);
    }
    vector<int> components;
    while (!unvisited.empty()) {
        stack<int> dfsStack;
        auto it { unvisited.begin() }; 
        dfsStack.push(*it);
        unvisited.erase(it);
        int compSize { 1 };
        while (!dfsStack.empty()) {
            int x { dfsStack.top() };
            dfsStack.pop();
            vector<int> toErase;
            for (const int& a : unvisited) {
                if (noEdge[x].find(a) != noEdge[x].end()) {
                    continue; 
                } 
                else {
                    dfsStack.push(a);
                    toErase.push_back(a);
                    compSize++;
                }
            } 
            for (const int& a : toErase) {
                unvisited.erase(a);
            }
        }
        components.push_back(compSize);
    }
    cout << components.size() << "\n";
    sort(components.begin(), components.end());
    for (const int& a : components) {
        cout << a;
        if (a == components.back()) {
            cout << "\n";
        }
        else {
            cout << " ";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
