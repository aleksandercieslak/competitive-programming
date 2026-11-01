#include <bits/stdc++.h>
using namespace std;

void solve() {
    int numberOfSights { 0 };
    cin >> numberOfSights;
    vector<int> beauty (numberOfSights);
    vector<int> value (numberOfSights);
    int mult { 0 };
    for (int i = 0; i < numberOfSights; i++) {
        cin >> beauty[i];
        value[i] = beauty[i]-mult;
        mult++;
    }
    vector<int> answers (3);
    vector<int> distances (3);
    for (int i = 0; i < 3; i++) {
        auto it { max_element(value.begin(), value.end()) };
        distances[i] = distance(value.begin(), it);
        answers[i] = *it+distances[i];
        value.erase(it);
    }
    cout << answers[0]+answers[1]+answers[2]-*max_element(distances.begin(), distances.end())+*min_element(distances.begin(), distances.end())+1 << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int numberOfTestCases { 0 };
    cin >> numberOfTestCases;
    for (int i = 0; i < numberOfTestCases; i++) {
        solve();
    }
}