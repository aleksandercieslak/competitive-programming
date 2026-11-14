#include <bits/stdc++.h>
using namespace std;

int n { 0 };
string numOne, numTwo;

int tooLarge(int multiplier, int factor, string num) {
    int t { multiplier*factor };
    string str { to_string(t) };
    while (str.length() != n) {
        str.insert(str.begin(), '0');       
    } 
    for (int i = 0; i < n; i++) {
        if (str[i] > num[i] && num[i] != '?') { return 1; }
        else if (str[i] < num[i] && num[i] != '?') { return 0; }
    }
    return 2; // 1 is its too large, 0 means its too small, 2 means its equal
}

bool valid(int factor) {
    
}

void solve() {
    cin >> n;
    cin >> numOne >> numTwo;
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
