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
    vector<long long> div;
    for (int i = n; i >= 1; i--) {
        if (pref[n-1]%i == 0) { div.push_back(pref[n-1]/i); }
    }
    for (const long long& a : div) {
        long long temp { 0 };
        while (temp < pref[n-1]) {
            long long val { *lower_bound(pref.begin(), pref.end(), temp+a) }; 
            if (val == temp+a) { temp+=a; }
            else { break; }
        }
        if (temp == pref[n-1]) {
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
