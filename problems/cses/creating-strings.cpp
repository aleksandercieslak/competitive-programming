#include <bits/stdc++.h>
using namespace std;

void search(string word, vector<string>& answers, string& permutation, vector<bool>& checked) {
    if (permutation.size() == word.length()) {
        if (count(answers.begin(), answers.end(), permutation) == 0) {
            answers.push_back(permutation);
        }
    }
    else {
        for (int i = 0; i < static_cast<int>(word.length()); i++) {
            if (checked[i] == true) { continue; }
            checked[i] = true;
            permutation.push_back(word[i]);
            search(word, answers, permutation, checked);
            checked[i] = false;
            permutation.pop_back();
        }
    }
}

void solve() {
    string word;
    cin >> word;
    vector<string> answers;
    string permutation;
    vector<bool> checked (word.length());
    search(word, answers, permutation, checked);
    cout << answers.size() << "\n";
    for (int i = 0; i < static_cast<int>(answers.size()); i++) {
        cout << answers[i] << "\n";
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}