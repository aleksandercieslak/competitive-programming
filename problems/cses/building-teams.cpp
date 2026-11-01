#include <bits/stdc++.h>
using namespace std;

int numberOfPupils { 0 };
int numberOfFriendships { 0 };
vector<vector<int>> friendships;
vector<int> assigned;
bool possible { true };

void dfs(int k, int color) {
    assigned[k] = color;
    for (auto u : friendships[k]) {
        if (assigned[u] == 0) {
            dfs(u, 3-color);
        }
        else if (assigned[k] == assigned[u]) {
            possible = false;
            break;
        }
    }
}

void solve() {
    cin >> numberOfPupils >> numberOfFriendships;
    friendships.resize(numberOfPupils);
    assigned.resize(numberOfPupils);
    for (int i = 0; i < numberOfFriendships; i++) {
        int a, b;
        cin >> a >> b;
        friendships[a-1].push_back(b-1);
        friendships[b-1].push_back(a-1);
    }
    for (int i = 0; i < numberOfPupils; i++) {
        if (assigned[i] == 0) {
            dfs(i, 1);
        }
    }
    if (possible) {
        for (int i = 0; i < numberOfPupils; i++) {
            cout << assigned[i];
            if (i < numberOfPupils-1) {
                cout << " ";
            }
            else {
                cout << "\n";
            }
        }
    }
    else {
        cout << "IMPOSSIBLE" << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
