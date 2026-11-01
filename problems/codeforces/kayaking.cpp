#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n { 0 };
    cin >> n;
    vector<int> people (2*n);
    for (int i = 0; i < 2*n; i++) {
        cin >> people[i];
    }
    sort(people.begin(), people.end());
    int instabilityLight { 0 };
    int instabilityHeavy { 0 };
    vector<int> peopleLight = people;
    peopleLight.pop_back(); peopleLight.pop_back();
    vector<int> peopleHeavy = people;
    peopleHeavy.erase(peopleHeavy.begin()); peopleHeavy.erase(peopleHeavy.begin());
    for (int i = 0; i < 2*n-2; i+=2) {
        instabilityLight += peopleLight[i+1] - peopleLight[i];
        instabilityHeavy += peopleHeavy[i+1] - peopleHeavy[i];
    }
    cout << min(instabilityLight, instabilityHeavy) << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}