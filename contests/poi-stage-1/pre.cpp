#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n { 0 };
    cin >> n;
    if ((n*(n+1)/2)%2 == 0) { cout << "TAK"; }
    else { cout << "NIE"; }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
