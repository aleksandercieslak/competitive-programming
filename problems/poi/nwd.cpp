#include <bits/stdc++.h>
using namespace std;

bool match(const string& a, const string& b, const int& n) {
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i] && a[i] != '?') { return false; }
    }
    return true;
}

void solve() {    
    int n { 0 }; 
    cin >> n;
    string firWord, secWord;
    cin >> firWord >> secWord;
    int q1 { 0 };
    int q2 { 0 };
    for (int i = 0; i < n; i++) {
        if (firWord[i] == '?') { q1++; }
        if (secWord[i] == '?') { q2++; }
    }
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
    if (q1 == 0 && q2 == 0) {
        for (int i = lim; i >= 1; i--) {
            if (t1%i == 0 && t2%i == 0) {
                cout << i << "\n";
                break;
            }
        }
    }
    else {
        for (int i = lim; i >= 1; i--) {
            pair<bool, bool> check;
            for (int j = 1; j <= biggest/i; j++) {
                string temp { to_string(i*j) };
                while (static_cast<int>(temp.size()) < n) {
                    temp.insert(temp.begin(), '0'); 
                }
                if (!check.first && match(firWord, temp, n)) { check.first = true; } 
                if (!check.second && match(secWord, temp, n)) { check.second = true; } 
                if (check.first && check.second) { break; }
            } 
            if (check.first && check.second) {
                cout << i << "\n";
                break;
            }  
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
