#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> logos (3); 
vector<pair <int, int>> subset;
int answer { 0 };
vector<vector<char>> board;

void search(int k) {
    if (k == 3) {
        if (subset[0].first + subset[1].first + subset[2].first == subset[0].second && subset[0].second == subset[1].second && subset[0].second == subset[2].second) {
            answer = subset[0].second;
            board.clear();
            for (int i = 0; i < subset[0].first; i++) {
                vector<char> temp;
                for (int j = 0; j < subset[0].second; j++) {
                    temp.push_back('A');
                }
                board.push_back(temp);
            }
            for (int i = 0; i < subset[1].first; i++) {
                vector<char> temp;
                for (int j = 0; j < subset[1].second; j++) {
                    temp.push_back('B');
                }
                board.push_back(temp);
            }
            for (int i = 0; i < subset[2].first; i++) {
                vector<char> temp;
                for (int j = 0; j < subset[2].second; j++) {
                    temp.push_back('C');
                }
                board.push_back(temp);
            }
        }
        else if (subset[1].first == subset[2].first && subset[0].first + subset[1].first == subset[1].second + subset[2].second && subset[0].second == subset[1].second + subset[2].second) {
            answer = subset[0].second;
            board.clear();
            for (int i = 0; i < subset[0].first; i++) {
                vector<char> temp;
                for (int j = 0; j < subset[0].second; j++) {
                    temp.push_back('A');
                }
                board.push_back(temp);
            }
            for (int i = 0; i < subset[1].first + subset[2].first; i++) {
                vector<char> temp;
                for (int j = 0; j < subset[1].second; j++) {
                    temp.push_back('B');
                }
                for (int j = 0; j < subset[2].second; j++) {
                    temp.push_back('C');
                }
                board.push_back(temp);
            }   
        }
        else if (subset[0].first == subset[2].first && subset[1].first + subset[0].first == subset[0].second + subset[2].second && subset[1].second == subset[0].second + subset[2].second) {
            answer = subset[1].second;
            board.clear();
            for (int i = 0; i < subset[1].first; i++) {
                vector<char> temp;
                for (int j = 0; j < subset[1].second; j++) {
                    temp.push_back('B');
                }
                board.push_back(temp);
            }
            for (int i = 0; i < subset[0].first + subset[2].first; i++) {
                vector<char> temp;
                for (int j = 0; j < subset[0].second; j++) {
                    temp.push_back('A');
                }
                for (int j = 0; j < subset[2].second; j++) {
                    temp.push_back('C');
                }
                board.push_back(temp);
            }
        }
        else if (subset[0].first == subset[1].first && subset[2].first + subset[1].first == subset[1].second + subset[0].second && subset[2].second == subset[1].second + subset[0].second) {
            answer = subset[2].second;
            board.clear();
            for (int i = 0; i < subset[2].first; i++) {
                vector<char> temp;
                for (int j = 0; j < subset[2].second; j++) {
                    temp.push_back('C');
                }
                board.push_back(temp);
            }
            for (int i = 0; i < subset[0].first + subset[1].first; i++) {
                vector<char> temp;
                for (int j = 0; j < subset[0].second; j++) {
                    temp.push_back('A');
                }
                for (int j = 0; j < subset[1].second; j++) {
                    temp.push_back('B');
                }
                board.push_back(temp);
            }
        }

    }        
    else {
        subset.push_back({logos[k].first, logos[k].second});
        search(k+1);
        subset.pop_back();
        subset.push_back({logos[k].second, logos[k].first});
        search(k+1); 
        subset.pop_back();
    }
}

void solve() {
    for (int i = 0; i < 3; i++) {
        cin >> logos[i].first >> logos[i].second;
    }
    search(0);
    if (answer == 0) { cout << -1 << "\n"; }
    else {
        cout << answer << "\n";
        for (int i = 0; i < static_cast<int>(board.size()); i++) {
            for (int j = 0; j < static_cast<int>(board.size()); j++) {
                cout << board[i][j];
            }
            cout << "\n";
        }
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}