#include <bits/stdc++.h>
using namespace std;

void solve() {
    int size { 0 };
    int numberOfQueries { 0 };
    cin >> size >> numberOfQueries;
    vector<int> numbers (size);
    for (int i = 0; i < size; i++) {
        cin >> numbers[i];
    }
    vector<int> frequency (size+1);
    for (int i = 0; i < numberOfQueries; i++) {
        int left;
        int right;
        cin >> left >> right;
        frequency[left-1]++;
        frequency[right]--;
    }
    for (int i = 1; i < size; i++) {
        frequency[i] += frequency[i-1];
    }
    sort(numbers.begin(), numbers.end());
    sort(frequency.begin(), frequency.begin()+size);
    int answer { 0 };
    for (int i = 0; i < size; i++) {
        answer += numbers[i]*frequency[i];
    }
    cout << answer << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}