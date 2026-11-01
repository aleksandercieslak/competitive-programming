#include <bits/stdc++.h>
using namespace std;

void solve() {
    int sequenceLength { 0 };
    cin >> sequenceLength;
    vector<int> a (sequenceLength);
    vector<int> b (sequenceLength);
    vector<int> c (sequenceLength);
    for (int i = 0; i < sequenceLength; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < sequenceLength; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < sequenceLength; i++) {
        cin >> c[i];
    }
    unordered_map<int, int> frequency;
    for (auto x : a) {
        frequency[x]++;
    }
    long long counter { 0 };
    for (auto x : c) {
        counter += frequency[b[x-1]];
    }
    cout << counter << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}