#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n { 0 };
    int m { 0 };
    cin >> n >> m;
    vector<int> attack;
    vector<int> defense;
    for (int i = 0; i < n; i++) {
        string s;
        int a;
        cin >> s >> a;
        if (s == "ATK") {
            attack.push_back(a);
        }
        else {
            defense.push_back(a);
        }
    }
    vector<int> ciel (m);
    for (int& a : ciel) {
        cin >> a;
    }
    sort(attack.begin(), attack.end());
    sort(defense.begin(), defense.end());
    sort(ciel.begin(), ciel.end());
    vector<bool> taken (m);
    vector<int> forDefense;
    vector<int> forAttack;
    if (m > n) {
        for (int i = 0; i < static_cast<int>(defense.size()); i++) {
            bool con { false };
            for (int j = 0; j < m; j++) {
                if (!taken[j] && ciel[j] > defense[i]) {
                    taken[j] = true; 
                    forDefense.push_back(ciel[j]);
                    con = true;
                    break;
                }
            }
            if (con) {
                continue;
            }
        }
        for (int i = 0; i < static_cast<int>(attack.size()); i++) {
            bool con { false };
            for (int j = 0; j < m; j++) {
                if (!taken[j] && ciel[j] >= attack[i]) {
                    taken[j] = true; 
                    forAttack.push_back(ciel[j]);
                    con = true;
                    break;
                }
            }
            if (con) {
                continue;
            }
        }
    }
    int sum1 { 0 };
    int index { 0 };
    if (forAttack.size() == attack.size() && forDefense.size() == defense.size()) {
        for (int i = 0; i < m; i++) {
            if (!taken[i]) {
                sum1 += ciel[i];
            }
            else {
                if (index < static_cast<int>(forAttack.size()) && forAttack[index] == ciel[i]) {
                    sum1 += forAttack[index] - attack[index];
                    index++;
                }
            }
        }
    }
    int sum2 { 0 };
    int k { 0 };
    sort(ciel.begin(), ciel.end(), [](const int& a, const int& b) { return a > b; });
    while (k < static_cast<int>(ciel.size()) && k < static_cast<int>(attack.size())) {
        if (ciel[k] > attack[k]) {
            sum2 += ciel[k] - attack[k];
        }
        k++;
    }
    cout << max(sum1, sum2) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
