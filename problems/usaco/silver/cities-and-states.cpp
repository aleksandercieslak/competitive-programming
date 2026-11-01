#include <bits/stdc++.h>
using namespace std;

void solve() {
    int numberOfCities { 0 };
    cin >> numberOfCities;
    unordered_map<string, string> cities;
    for (int i = 0; i < numberOfCities; i++) {
        string city;
        string state;
        cin >> city >> state;
        string temp;
        temp += city[0];
        temp += city[1];
        cities[temp] = state;            
    }
    int counter { 0 };
    for (auto a : cities) {
        if (cities[a.second] == a.first) {
            counter++;
        }
    }
    counter /= 2;
    cout << counter << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}