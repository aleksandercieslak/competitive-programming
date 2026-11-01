#include <bits/stdc++.h>
using namespace std;

void solve() {
    int length { 0 };
    int x { 0 };
    cin >> length >> x;
    vector<int> books (length);
    for (int i = 0; i < length; i++) {
        cin >> books[i];
    }
    int i { 0 };
    int j { 0 };
    int answer { 0 };
    int sum { books[i] };
    while (i < length-1 && j < length) {
        if (sum <= x) {
            answer = max(answer, abs(j-i)+1);
            sum += books[i+1];
            i++;
        }
        else if (sum > x) {
            sum -= books[j];
            j++;
        }
    }
    cout << answer << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}