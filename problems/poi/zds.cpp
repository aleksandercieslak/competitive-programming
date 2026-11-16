#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n { 0 };
    int k { 0 };
    cin >> n >> k;
    struct Info {
        int p;
        int c;
        int t;
    };
    vector<Info> projects (n);
    for (auto& a : projects) {
        cin >> a.p >> a.c >> a.t;
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
