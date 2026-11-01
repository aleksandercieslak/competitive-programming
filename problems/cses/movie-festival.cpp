#include <bits/stdc++.h>
using namespace std;

void solve() {
    int numberOfMovies { 0 };
    cin >> numberOfMovies;
    vector<pair<int, int>> movies (numberOfMovies);
    for (auto& a : movies) {
        cin >> a.first >> a.second;
    }
    sort(movies.begin(), movies.end(), [](const auto& a, const auto& b) { return a.second < b.second; });
    int answer { 1 };
    int current { movies[0].second };
    for (int i = 1; i < numberOfMovies; i++) {
        if (movies[i].first >= current) {
            current = movies[i].second;
            answer++;
        }
    }
    cout << answer << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}