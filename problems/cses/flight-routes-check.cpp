#include <bits/stdc++.h>
using namespace std;

void solve() {
    int numberOfCities { 0 };
    int numberOfFlights { 0 };
    cin >> numberOfCities >> numberOfFlights;
    vector<vector<int>> flightsFrom (numberOfCities);
    vector<vector<int>> flightsTo (numberOfCities);
    for (int i = 0; i < numberOfFlights; i++) {
        int a, b;
        cin >> a >> b;
        flightsFrom[a-1].push_back(b-1);
        flightsTo[b-1].push_back(a-1);
    }
    vector<bool> visitedTo (numberOfCities);
    stack<int> dfsStackTo;
    dfsStackTo.push(0);
    while (!dfsStackTo.empty()) {
        int temp { dfsStackTo.top() };
        dfsStackTo.pop();
        visitedTo[temp] = true;
        for (const auto& a : flightsFrom[temp]) {
            if (!visitedTo[a]) {
                dfsStackTo.push(a);
            }
        }
    }
    vector<bool> visitedFrom (numberOfCities);
    stack<int> dfsStackFrom;
    dfsStackFrom.push(0);
    while (!dfsStackFrom.empty()) {
        int temp { dfsStackFrom.top() };
        dfsStackFrom.pop();
        visitedFrom[temp] = true;
        for (const auto& a : flightsTo[temp]) {
            if (!visitedFrom[a]) {
                dfsStackFrom.push(a);
            }
        }
    }
    int sumTo { 0 };
    int sumFrom { 0 };
    pair<int, int> example {0, 0};
    for (int i = 0; i < numberOfCities; i++) {
        sumTo += visitedTo[i];
        if (visitedTo[i] == 0 && example.first == 0 && example.second == 0) {
            example = {1, i+1};
        }
    }
    for (int i = 0; i < numberOfCities; i++) {
        sumFrom += visitedFrom[i];
        if (visitedFrom[i] == 0 && example.first == 0 && example.second == 0) {
            example = {i+1, 1};
        }
    }
    if (sumTo == sumFrom && sumFrom == numberOfCities) {
        cout << "YES" << "\n";
    }
    else {
        cout << "NO" << "\n";
        cout << example.first << " " << example.second << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
