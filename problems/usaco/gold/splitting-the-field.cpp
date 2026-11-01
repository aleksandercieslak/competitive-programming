#include <bits/stdc++.h>
using namespace std;

void solve() {
    int numberOfCows { 0 };
    cin >> numberOfCows;
    vector<pair<int, int>> cows (numberOfCows);
    for (int i = 0; i < numberOfCows; i++) {
        cin >> cows[i].first >> cows[i].second;
    }
    int baseArea { 0 };
    int l { 1000000000 };
    int r { 0 };
    int b { 1000000000 };
    int t { 0 };
    for (int i = 0; i < numberOfCows; i++) {
        l = min(cows[i].first, l);
        r = max(cows[i].first, r);
        b = min(cows[i].second, b);
        t = max(cows[i].second, t);
    }
    baseArea = (r-l)*(t-b);
    struct Edge {
        int left;
        int right;
        int bottom;
        int top;
    };
    sort(cows.begin(), cows.end(), [](pair<int, int> a, pair<int, int> b) { return a.first < b.first; });
    vector<Edge> horizontalPrefix (numberOfCows);
    horizontalPrefix[0].left = cows[0].first;
    horizontalPrefix[0].right = cows[0].first;
    horizontalPrefix[0].bottom = cows[0].second;
    horizontalPrefix[0].top = cows[0].second;
    for (int i = 1; i < numberOfCows; i++) {
        horizontalPrefix[i].left = min(cows[i].first, horizontalPrefix[i-1].left);
        horizontalPrefix[i].right = max(cows[i].first, horizontalPrefix[i-1].right);
        horizontalPrefix[i].bottom = min(cows[i].second, horizontalPrefix[i-1].bottom);
        horizontalPrefix[i].top = max(cows[i].second, horizontalPrefix[i-1].top);
    }
    vector<Edge> horizontalSuffix (numberOfCows);
    horizontalSuffix[numberOfCows-1].left = cows[numberOfCows-1].first;
    horizontalSuffix[numberOfCows-1].right = cows[numberOfCows-1].first;
    horizontalSuffix[numberOfCows-1].bottom = cows[numberOfCows-1].second;
    horizontalSuffix[numberOfCows-1].top = cows[numberOfCows-1].second;
    for (int i = numberOfCows-2; i >= 0; i--) {
        horizontalSuffix[i].left = min(cows[i].first, horizontalSuffix[i+1].left);
        horizontalSuffix[i].right = max(cows[i].first, horizontalSuffix[i+1].right);
        horizontalSuffix[i].bottom = min(cows[i].second, horizontalSuffix[i+1].bottom);
        horizontalSuffix[i].top = max(cows[i].second, horizontalSuffix[i+1].top);
    }
    sort(cows.begin(), cows.end(), [](pair<int, int> a, pair<int, int> b) { return a.second < b.second; });
    vector<Edge> verticalPrefix (numberOfCows);
    verticalPrefix[0].left = cows[0].first;
    verticalPrefix[0].right = cows[0].first;
    verticalPrefix[0].bottom = cows[0].second;
    verticalPrefix[0].top = cows[0].second;
    for (int i = 1; i < numberOfCows; i++) {
        verticalPrefix[i].left = min(cows[i].first, verticalPrefix[i-1].left);
        verticalPrefix[i].right = max(cows[i].first, verticalPrefix[i-1].right);
        verticalPrefix[i].bottom = min(cows[i].second, verticalPrefix[i-1].bottom);
        verticalPrefix[i].top = max(cows[i].second, verticalPrefix[i-1].top);
    }
    vector<Edge> verticalSuffix (numberOfCows);
    verticalSuffix[numberOfCows-1].left = cows[numberOfCows-1].first;
    verticalSuffix[numberOfCows-1].right = cows[numberOfCows-1].first;
    verticalSuffix[numberOfCows-1].bottom = cows[numberOfCows-1].second;
    verticalSuffix[numberOfCows-1].top = cows[numberOfCows-1].second;
    for (int i = numberOfCows-2; i >= 0; i--) {
        verticalSuffix[i].left = min(cows[i].first, verticalSuffix[i+1].left);
        verticalSuffix[i].right = max(cows[i].first, verticalSuffix[i+1].right);
        verticalSuffix[i].bottom = min(cows[i].second, verticalSuffix[i+1].bottom);
        verticalSuffix[i].top = max(cows[i].second, verticalSuffix[i+1].top);
    }
    int newArea { baseArea };
    for (int i = 1; i < numberOfCows; i++) {
        int leftArea { (horizontalPrefix[i-1].top-horizontalPrefix[i-1].bottom)*(horizontalPrefix[i-1].right-horizontalPrefix[i-1].left) };
        int rightArea { (horizontalSuffix[i].top-horizontalSuffix[i].bottom)*(horizontalSuffix[i].right-horizontalSuffix[i].left) };
        int bottomArea { (verticalPrefix[i-1].top-verticalPrefix[i-1].bottom)*(verticalPrefix[i-1].right-verticalPrefix[i-1].left) };
        int topArea { (verticalSuffix[i].top-verticalSuffix[i].bottom)*(verticalSuffix[i].right-verticalSuffix[i].left) };
        newArea = min(newArea, min(leftArea+rightArea, bottomArea+topArea));
    }
    cout << baseArea - newArea << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}