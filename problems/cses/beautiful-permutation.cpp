#include <bits/stdc++.h>
using namespace std;

void solve() {
    int input { 0 };
    cin >> input;
    vector<int> numbers;
    vector<int> answer;
    if (input <= 4) { cout << "NO SOLUTION" << "\n"; }
    else {
    for (int i = 1; i <= input; i++) {
        numbers.push_back(i);
        answer.push_back(input-i+1);
    }
    do {
        bool relevant = true;
        for (int i = 1; i < input; i++) {
            if (abs(numbers[i]-numbers[i-1]) == 1) {
                relevant = false;
            }
        }
        if (relevant) {
            bool isSmaller = false;
            for (int i = 0; i < input; i++) {
                if (numbers[i] < answer[i]) {
                    isSmaller = true;
                    break;
                }
                else if (numbers[i] > answer[i]) { break; }
            }
            if (isSmaller) { answer = numbers; }
        }
    } while (next_permutation(numbers.begin(), numbers.end()));
    for (int i = 0; i < input; i++) {
        cout << answer[i] << " ";
    }
}
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}