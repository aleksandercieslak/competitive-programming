#include <bits/stdc++.h>
using namespace std;

void solve() {    
    int n { 0 }; 
    cin >> n;
    string firWord, secWord;
    cin >> firWord >> secWord;
    int t1 { 0 };
    int t2 { 0 };
    for (int i = n-1; i >= 0; i--) {
        if (firWord[i] == '?') {
            t1 += 9 * pow(10, n-1-i);
        } 
        else {
            t1 += (firWord[i] - '0') * pow(10, n-1-i);
        }
        if (secWord[i] == '?') {
            t2 += 9 * pow(10, n-1-i);
        }
        else {
            t2 += (secWord[i] - '0') * pow(10, n-1-i);
        }
    }
    int lim { min(t1, t2) };
    int biggest { max(t1 ,t2) };
    for (int i = lim; i >= 1; i--) {
        pair<bool, bool> check;
        for (int j = 1; j <= biggest/i; j++) {
            string temp { to_string(i*j) };
            while (static_cast<int>(temp.size()) < n) {
                temp.insert(temp.begin(), '0'); 
            }
            int c1 { 0 };
            int c2 { 0 };
            for (int k = 0; k < n; k++) {
                if (!check.first && (temp[k] == firWord[k] || firWord[k] == '?')) {
                    c1++; 
                } 
                if (!check.second && (temp[k] == secWord[k] || secWord[k] == '?')) {
                    c2++;
                }
            } 
            if (c1 == n) { check.first = true; }
            if (c2 == n) { check.second = true; }
        } 
        if (check.first && check.second) {
            cout << i << "\n";
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
