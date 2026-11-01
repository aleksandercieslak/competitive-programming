#include <bits/stdc++.h>
using namespace std;

bool valid(int highwayLength, vector<pair<int, int>> stations, double radius) {
    double current { 0 };
    for (auto a : stations) {
        double distance { pow(pow(radius, 2) - pow(static_cast<double>(a.second), 2), 0.5) };
        double pointLeft { a.first-distance };
        double pointRight { a.first+distance };
        if (pointLeft <= current) {
            current = pointRight;
        }
    }
    if (current >= highwayLength) {
        return true;
    }
    return false;
}

void solve() {
    int numberOfStations { 0 };
    int highwayLength { 0 };
    cin >> numberOfStations >> highwayLength;
    vector<pair<int, int>> stations (1);
    cin >> stations[0].first >> stations[0].second;
    for (int i = 1; i < numberOfStations; i++) {
        int a, b;
        cin >> a >> b;
        if (a != stations[i-1].first) {
            stations.push_back({a, b});
        }
    }
    double left { 0 };
    double right { pow(2, 0.5) * pow(10, 9) };
    while (right-left > 0.001) {
        double middle { (right+left)/2.0 };
        if (valid(highwayLength, stations, middle)) {
            right = middle;
        }
        else {
            left = middle+0.001;
        }
    }
    cout << (left+right)/2 << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}