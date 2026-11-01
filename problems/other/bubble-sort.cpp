#include <bits/stdc++.h>
using namespace std;

void solve() {
    int arrayLength { 0 };
    cin >> arrayLength;
    vector<int> numbers (arrayLength);
    for (int i = 0; i < arrayLength; i++) {
        cin >> numbers[i];
    }
    int counter { 0 };
    for (int i = 0; i < arrayLength; i++) {
        for (int j = 0; j < arrayLength-1; j++) {
            if (numbers[j] > numbers[j+1]) {
                int firstValue = numbers[j];
                numbers[j] = numbers[j+1];
                numbers[j+1] = firstValue;
                counter++;
            }
        }
    }
    cout << "Array is sorted in " << counter << " swaps.\n";
    cout << "First Element: " << numbers[0] << "\n";
    cout << "Last Element: " << numbers[arrayLength-1] << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}