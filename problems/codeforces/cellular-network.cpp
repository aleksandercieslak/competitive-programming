#include <bits/stdc++.h>
using namespace std;

void solve() {
    int numberOfCities { 0 };
    int numberOfTowers { 0 };
    cin >> numberOfCities >> numberOfTowers;
    vector<int> cities (numberOfCities);
    for (int i = 0; i < numberOfCities; i++) {
        cin >> cities[i];
    }
    vector<int> towers (numberOfTowers);
    for (int i = 0; i < numberOfTowers; i++) {
        cin >> towers[i];
    }
    sort(cities.begin(), cities.end());
    sort(towers.begin(), towers.end());
    for (int i = 1; i < numberOfCities; i++) {
        if (cities[i] == cities[i-1]) {
            cities.erase(cities.begin()+i);
        }
    }
    int r { 0 };
    for (int i = 0; i < numberOfCities; i++) {
        auto it { lower_bound(towers.begin(), towers.end(), cities[i]) };
        auto position { distance(towers.begin(), it) };
        if (it == towers.begin()) { r = max(r, towers[0]-cities[i]); }
        if (it == towers.end()) { r = max(r, cities[i]-towers[numberOfTowers-1]); }
        r = max(r, min(abs(towers[position]-cities[i]), abs(towers[position-1]-cities[i])));
    }
    cout << r << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}