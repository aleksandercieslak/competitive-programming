#include <bits/stdc++.h>
using namespace std;

void search(vector<int>& container, vector<int>& subset, int k, int weight, int& answer) {
    if (k == static_cast<int>(container.size())) {
        int subsetSum = subset.empty() ? 0 : reduce(subset.begin(), subset.end());
        answer = min(answer, abs(weight-2*subsetSum));        
    }
    else {
        search(container, subset, k+1, weight, answer);
        subset.push_back(container[k]);
        search(container, subset, k+1, weight, answer);
        subset.pop_back();
    }
}

void solve() {
    int numberOfApples { 0 };
    cin >> numberOfApples;
    vector<int> apples (numberOfApples);
    for (int i = 0; i < numberOfApples; i++) {
        cin >> apples[i];
    }
    vector<int> subset;
    int weight { reduce(apples.begin(), apples.end()) };
    int answer { weight };
    search(apples, subset, 0, weight, answer);
    cout << answer << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}