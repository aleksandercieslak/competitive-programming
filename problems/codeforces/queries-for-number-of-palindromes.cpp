#include <bits/stdc++.h>
using namespace std;

void solve() {
    string word;
    cin >> word;
    int length { static_cast<int>(word.length()) };
    vector<vector<int>> palindromes (length, vector<int>(length));
    vector<vector<bool>> isPalindrome (length, vector<bool>(length));
    for (int i = length-1; i >= 0; i--) {
        isPalindrome[i][i] = true;
        palindromes[i][i] = 1;
        for (int j = i+1; j < length; j++) {
            isPalindrome[i][j] = (isPalindrome[i+1][j-1] || j-i == 1) && (word[i] == word[j]);
            palindromes[i][j] = palindromes[i+1][j] + palindromes[i][j-1] - palindromes[i+1][j-1] + isPalindrome[i][j];
        }
    }
    int numberOfQueries { 0 };
    cin >> numberOfQueries;
    for (int i = 0; i < numberOfQueries; i++) {
        int left, right;
        cin >> left >> right;
        cout << palindromes[left-1][right-1] << "\n";
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
