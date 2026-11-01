#include <bits/stdc++.h>
using namespace std;

void solve() {
    int numberOfCustomers { 0 };
    cin >> numberOfCustomers;
    vector<pair<int, int>> customers (numberOfCustomers);
    for (auto& a : customers) {
        cin >> a.first >> a.second;
    }
    vector<pair<int, int>> temp { customers };
    vector<int> counter (numberOfCustomers);
    sort(customers.begin(), customers.end());
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> departures;
    int current { 0 };
    departures.push({customers[0].second, ++current});
    counter[0] = current;
    for (int i = 1; i < numberOfCustomers; i++) {
        if (customers[i].first > departures.top().first) {
            departures.push({customers[i].second, departures.top().second});
            counter[i] = departures.top().second;
            departures.pop(); 
        }
        else {
            departures.push({customers[i].second, ++current});
            counter[i] = current;
        }
    }
    cout << current << "\n";
    vector<int> plus (numberOfCustomers);
    bool first { true };
    for (const auto& a : temp) {
        auto it { lower_bound(customers.begin(), customers.end(), a) };
        auto index { it - customers.begin() };
        if (!first) {
            cout << " ";
        }
        cout << counter[index+plus[index]];
        plus[index]++;
        first = false;
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
