#include <bits/stdc++.h>
using namespace std;

void solve() {
    int arraySize { 0 };
    cin >> arraySize;
    vector<int> numbers (arraySize);
    vector<int> prefix (arraySize);
    for (int i = 0; i < arraySize; i++) {
        cin >> numbers[i];
        if (i == 0) {
            prefix[i] = numbers[i];
        }
        else {
            prefix[i] = numbers[i-1] + numbers[i];
        }
    }
    auto itMax { max_element(prefix.begin(), prefix.end()) };
    int minEl { 0 };
    for (auto i = itMax-1; i >= prefix.begin(); i--) {
        if (*i < 0) {
            minEl = *i;
            break;
        }
    }
    cout << *itMax-minEl << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}