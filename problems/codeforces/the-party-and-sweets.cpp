#include <bits/stdc++.h>
using namespace std;

void solve() {
    int numberOfBoys { 0 };
    int numberOfGirls { 0 };
    cin >> numberOfBoys >> numberOfGirls;
    vector<int> boys (numberOfBoys);
    for (int& a : boys) {
        cin >> a;
    }
    vector<int> girls (numberOfGirls);
    for (int& a : girls) {
        cin >> a;
    }
    sort(boys.begin(), boys.end());
    sort(girls.begin(), girls.end());
    if (girls.front() < boys.back()) {
        cout << -1 << "\n"; 
    }
    else {
        vector<int> counter (numberOfBoys);
        vector<int> copy { boys };
        int answer { 0 };
        while (!boys.empty() && !girls.empty()) {
            if ((counter[static_cast<int>(boys.size())-1] == numberOfGirls-1 && girls.back() == boys.back()) || (girls.back() >= boys.back() && counter[static_cast<int>(boys.size())-1] < numberOfGirls-1)) {
                answer += girls.back();
                counter[static_cast<int>(boys.size())-1]++;
                girls.pop_back();
            } 
            else {
                boys.pop_back();
            }
        }
        for (int i = 0; i < numberOfBoys; i++) {
            answer += copy[i] * (numberOfGirls-counter[i]); 
        }
        cout << answer << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
