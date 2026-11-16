#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n { 0 }; 
    cin >> n; 
    vector<int> connected (n);
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        connected[a-1]++;
        connected[b-1]++;
    }
    cout << 1+*max_element(connected.begin(), connected.end()) << "\n"; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
