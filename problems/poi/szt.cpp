#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n { 0 };
    cin >> n;
    vector<int> num (n);
    for (int& a : num) {
        cin >> a;
    }
    vector<long long> pref (n);
    pref[0] = num[0];
    for (int i = 1; i < n; i++) {
        pref[i] = pref[i-1]+num[i];
    }
    vector<int> div;
    for (int i = n; i >= 1; i--) {
        if (pref[n-1]%i == 0) { div.push_back(pref[n-1]/i); }
    }
    for (const int& a : div) {
        long long t { 0 };
        for (const int& b : num) {
            t += b;
            if (t > a) { break; }
            else if (t == a) { t = 0; }
        }
        if (t == 0) {
            cout << pref[n-1]/a << "\n"; 
            break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
