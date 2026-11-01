#include <bits/stdc++.h>
using namespace std;

void solve() {
    int numberOfQueries { 0 };
    cin >> numberOfQueries;
    unordered_map<int, int> queries;
    for (int i = 0; i < numberOfQueries; i++) {
        int type, index, value;
        cin >> type >> index;
        if (type == 0) {
            cin >> value;
            queries[index] = value;            
        }
        else {
            cout << queries[index] << "\n";
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}