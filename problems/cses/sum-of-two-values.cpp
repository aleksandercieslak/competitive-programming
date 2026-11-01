#include <bits/stdc++.h>
using namespace std;

void solve() {
    int arraySize { 0 };
    int x { 0 };
    cin >> arraySize >> x;
    vector<int> numbers (arraySize);
    for (int i = 0; i < arraySize; i++) {
        cin >> numbers[i];
    }
    unordered_map<int, vector<int>> indices;
    for (int i = 0; i < arraySize; i++) {
        indices[numbers[i]].push_back(i);
    }
    int i { 0 };
    int j { arraySize-1 };
    sort(numbers.begin(), numbers.end());
    while (i < j) {
        if (numbers[i] + numbers[j] == x) {
            int first { indices[numbers[i]][0] };
            int second { 0 };
            if (numbers[i] == numbers[j]) {
                second = indices[numbers[j]][1];
            }
            else {
                second = indices[numbers[j]][0];
            }
            cout << first+1 << " " << second+1 << "\n";
            break;
        }
        if (numbers[i] + numbers[j] > x) {
            j--;
        }
        if (numbers[i] + numbers[j] < x) {
            i++;
        }
    }
    if (i >= j) {
        cout << "IMPOSSIBLE\n";
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}