#include <bits/stdc++.h>
using namespace std;

void solve() {
    int length { 0 };
    int x { 0 };
    cin >> length >> x;
    vector<int> numbers (length);
    for (int i = 0; i < length; i++) {
        cin >> numbers[i];
    }
    bool found { false };
    unordered_map<int, vector<int>> indices;
    for (int i = 0; i < length; i++) {
        indices[numbers[i]].push_back(i);
    }
    sort(numbers.begin(), numbers.end());
    for (int k = 0; k < length; k++) {
        int i { 0 };
        int j { length-1 };
        while (i < j) {
            if (numbers[i] + numbers[j] + numbers[k] == x) {
                int indexOne { indices[numbers[i]][0] };
                int indexTwo { indices[numbers[j]][0] };
                int indexThree { indices[numbers[k]][0] };
                if (numbers[j] == numbers[i]) {
                    indexTwo = indices[numbers[j]][1];
                    if (numbers[k] == numbers[j]) {
                        indexThree = indices[numbers[k]][2];
                    }
                }
                else if (numbers[k] == numbers[j] || numbers[k] == numbers[i]) {
                    indexThree = indices[numbers[k]][1];
                }
                cout << indexOne+1 << " " << indexTwo+1 << " " << indexThree+1 << "\n";
                found = true;
                break;
            }
            else if (numbers[i] + numbers[j] + numbers[k] < x) {
                i++;
                if (k == i) { i++; }
            }
            else if (numbers[i] + numbers[j] + numbers[k] > x) {
                j--;
                if (k == j) { j--; }
            }
        }
        if (found) { break; }
    }
    if (!found) {
        cout << "IMPOSSIBLE\n";
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}