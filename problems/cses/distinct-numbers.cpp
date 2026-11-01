#include <bits/stdc++.h>
using namespace std;

void search() {
    int numberOfValues { 0 };
    cin >> numberOfValues;
    set<int> numbers;
    for (int i = 0; i < numberOfValues; i++) {
        int var;
        cin >> var;
        numbers.emplace(var);
    }
    cout << numbers.size() << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    search();
}