#include <bits/stdc++.h>
using namespace std;

void solve() {
    int length { 0 };
    int numberOfQueries { 0 };
    cin >> length >> numberOfQueries;
    vector<int> sequence (length);
    for (int i = 0; i < length; i++) {
        cin >> sequence[i];
    }
    vector<int> prefix (length);
    prefix[0] = sequence[0];
    for (int i = 1; i < length; i++) {
        prefix[i] = prefix[i-1] + sequence[i];
    }
    for (int q = 0; q < numberOfQueries; q++) {
        int indexOne, indexTwo;
        cin >> indexOne >> indexTwo;
        if (indexOne > 0) {
            cout << prefix[indexTwo-1] - prefix[indexOne-1] << "\n";
        }
        else {
            cout << prefix[indexTwo-1] << "\n";
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}