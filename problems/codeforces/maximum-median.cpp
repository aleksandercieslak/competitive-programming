#include <bits/stdc++.h>
using namespace std;

void solve() {
    int length { 0 };
    int operations { 0 };
    cin >> length >> operations;
    vector<int> numbers (length);
    for (int i = 0; i < length; i++) {
        cin >> numbers[i];
    }
    sort(numbers.begin(), numbers.end());
    int current { length/2 };
    int members { 1 };
    int median { numbers[current] };
    while (current+1 < length && operations >= (numbers[current+1]-numbers[current])*members) {
        while (current+1 < length && numbers[current] == numbers[current+1]) {
            current++;
            members++;
        }
        if (current >= length-1) { median += operations/members; break; }
        median = numbers[current+1];
        operations -= (numbers[current+1]-numbers[current])*members;
        current++;
        members++;
    }
    cout << median << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}