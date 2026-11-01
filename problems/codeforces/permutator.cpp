#include <bits/stdc++.h>
using namespace std;

void solve() {
    int numberOfElements { 0 };
    cin >> numberOfElements;
    vector<int> a (numberOfElements);
    vector<int> b (numberOfElements);
    for (int i = 0; i < numberOfElements; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < numberOfElements; i++) {
        cin >> b[i];
    }
    vector<int> weightedA;
    for (int k = 0; k < numberOfElements; k++) {
        weightedA.push_back( (k+1)*(numberOfElements-k)*a[k] );
    }
    sort(weightedA.begin(), weightedA.end(), [](int a, int b) { return a > b; });
    sort(b.begin(), b.end());
    int counter { 0 };
    for (int i = 0; i < numberOfElements; i++) {
        counter += weightedA[i]*b[i];
    }
    cout << counter << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}