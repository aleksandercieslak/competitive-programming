#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 9;

void solve() {
    int length { 0 };
    int difference { 0 };
    cin >> length >> difference;
    vector<int> blocks (length);
    for (int i = 0; i < length; i++) {
        cin >> blocks[i];
    }
    int answer { 1 };
    sort(blocks.begin(), blocks.end());
    for (int i = 0; i < length; i++) {
        int j { i };
        while (j < length-1 && blocks[j+1]-blocks[i] <= difference) { j++; }
        int distance { j-i+1 };
        answer = (answer * distance) % MOD;
    }
    cout << answer << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
