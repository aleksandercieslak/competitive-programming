#include <bits/stdc++.h>
using namespace std;

void solve() {
    int numberOfTestCases { 0 };
    cin >> numberOfTestCases;
    for (int t = 0; t < numberOfTestCases; t++) {
        int sequenceLength { 0 };
        cin >> sequenceLength;
        vector<int> sequence (sequenceLength);
        string temp;
        cin >> temp;
        for (int i = 0; i < sequenceLength; i++) {
            sequence[i] = temp[i] - '0';
        }
        vector<int> prefix (sequenceLength);
        prefix[0] = sequence[0];
        for (int i = 1; i < sequenceLength; i++) {
            prefix[i] = prefix[i-1] + sequence[i];
        }
        unordered_map<int, int> appearances;
        appearances[0] = 1; 
        for (int i = 0; i < sequenceLength; i++) {
            appearances[prefix[i]-i-1]++;
        }
        int answer { 0 };
        for (auto a : appearances) {
            answer += a.second * (a.second-1) / 2;
        } 
        cout << answer << "\n";
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}