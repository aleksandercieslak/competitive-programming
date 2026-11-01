#include <bits/stdc++.h>
using namespace std;

bool isPossible(const vector<long long> &array, const int maxDiv, const long long maxSum) {
    long long current { 0 };
    int counter { 0 };
    for (int a : array) {
        if (a > maxSum) { return false; }
        if (current + a > maxSum) {
            counter++;
            current = 0;
        }
        current += a;
    }
    if (current > 0) { counter++; }
    return counter <= maxDiv;
}

void solve() {
    int length { 0 };
    int divisions { 0 };
    cin >> length >> divisions;
    vector<long long> numbers (length);
    for (int i = 0; i < length; i++) {
        cin >> numbers[i];
    }
    long long left { *max_element(numbers.begin(), numbers.end()) };
    long long right { reduce(numbers.begin(), numbers.end()) };
    while (left < right) {
        long long middle { (left+right)/2 };
        if (isPossible(numbers, divisions, middle)) {
            right = middle;
        }
        else {
            left = middle+1;
        }
    }
    cout << left << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}