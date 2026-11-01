#include <bits/stdc++.h>
using namespace std;

int numberOfCities { 0 };
int numberOfRoads { 0 };
vector<bool> visited (numberOfCities);
vector<vector<int>> roads (numberOfCities);

void dfs(int k) {
    if (visited[k]) { return; }
    visited[k] = true;
    for (auto u : roads[k]) {
        dfs(u);
    }
}

void solve() {
    cin >> numberOfCities >> numberOfRoads;
    visited.resize(numberOfCities);
    roads.resize(numberOfCities);
    for (int i = 0; i < numberOfRoads; i++) {
        int a, b;
        cin >> a >> b;
        roads[a-1].push_back(b-1);
        roads[b-1].push_back(a-1);
    }
    vector<int> examples;
    for (int i = 0; i < numberOfCities; i++) {
       if (!visited[i]) {
           dfs(i);
           examples.push_back(i);
       }     
    }
    int answer { static_cast<int>(examples.size() - 1) };
    cout << answer << "\n";
    for (int i = 0; i < answer; i++) {
        cout << examples[i]+1 << " " << examples[i+1]+1 << "\n"; 
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
