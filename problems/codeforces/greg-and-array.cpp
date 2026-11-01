#include <bits/stdc++.h>
using namespace std;

struct Info {
    int left;
    int right;
    int value;
};

void solve() {
    int arraySize;
    int numberOfOperations;
    int numberOfQueries;
    cin >> arraySize >> numberOfOperations >> numberOfQueries;
    vector<int> numbers (arraySize+1);
    for (int i = 0; i < arraySize; i++) {
        cin >> numbers[i];
    }
    vector<Info> operations (numberOfOperations);
    for (int i = 0; i < numberOfOperations; i++) {
        cin >> operations[i].left >> operations[i].right >> operations[i].value;
    }
    vector<int> applied (numberOfOperations+1);
    for (int i = 0; i < numberOfQueries; i++) {
        int first;
        int second;
        cin >> first >> second;
        applied[first-1]++;
        applied[second]--;
    }
    for (int i = 1; i < numberOfOperations; i++) {
        applied[i] += applied[i-1];
    }
    vector<int> temp (arraySize+1);
    for (int i = 0; i < numberOfOperations; i++) {
        temp[operations[i].left-1] += applied[i]*operations[i].value;
        temp[operations[i].right] -= applied[i]*operations[i].value;
    }
    for (int i = 1; i < arraySize; i++) {
        temp[i] += temp[i-1];
    }
    for (int i = 0; i < arraySize; i++) {
        cout << numbers[i]+temp[i] << " ";
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}