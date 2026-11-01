#include <bits/stdc++.h>
using namespace std;

void solve() {
    int numberOfStacks { 0 };
    int numberOfQueries { 0 };
    cin >> numberOfStacks >> numberOfQueries;
    vector<int> stacks (numberOfStacks+1);
    for (int i = 0; i < numberOfQueries; i++) {
        int l, r;
        cin >> l >> r;
        stacks[l-1]++;
        stacks[r]--;
    }
    for (int i = 1; i < numberOfStacks; i++) {
        stacks[i] += stacks[i-1];
    }
    sort(stacks.begin(), stacks.begin()+numberOfStacks);
    cout << stacks[(numberOfStacks-1)/2] << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}