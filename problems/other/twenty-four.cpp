#include <bits/stdc++.h>
using namespace std;

vector<char> subsetOperators;
vector<int> subsetOrder;

void findOrder (int k, vector<int> cards, int& answer) {
    if (k == 2) {
        vector<char> operators = subsetOperators;
        if (operators[subsetOrder[0]] == '+') { cards[subsetOrder[0]] += cards[subsetOrder[0]+1]; }
        else if (operators[subsetOrder[0]] == '-') { cards[subsetOrder[0]] -= cards[subsetOrder[0]+1]; }
        else if (operators[subsetOrder[0]] == '*') { cards[subsetOrder[0]] *= cards[subsetOrder[0]+1]; }
        else if (operators[subsetOrder[0]] == '/' || cards[subsetOrder[0]+1] == 0 || cards[subsetOrder[0]]%cards[subsetOrder[0]+1] != 0) { return; } else { cards[subsetOrder[0]] /= cards[subsetOrder[0]+1]; }
        cards.erase(cards.begin() + subsetOrder[0]+1);
        operators.erase(operators.begin() + subsetOrder[0]);
        if (operators[subsetOrder[1]] == '+') { cards[subsetOrder[1]] += cards[subsetOrder[1]+1]; }
        else if (operators[subsetOrder[1]] == '-') { cards[subsetOrder[1]] -= cards[subsetOrder[1]+1]; }
        else if (operators[subsetOrder[1]] == '*') { cards[subsetOrder[1]] *= cards[subsetOrder[1]+1]; }
        else if (operators[subsetOrder[1]] == '/' || cards[subsetOrder[1]+1] == 0 || cards[subsetOrder[1]]%cards[subsetOrder[1]+1] != 0) { return; } else { cards[subsetOrder[1]] /= cards[subsetOrder[1]+1]; }
        cards.erase(cards.begin() + subsetOrder[1]+1);
        operators.erase(operators.begin() + subsetOrder[1]);
        if (operators[0] == '+') { cards[0] += cards[1]; }
        else if (operators[0] == '-') { cards[0] -= cards[1]; }
        else if (operators[0] == '*') { cards[0] *= cards[1]; }
        else if (operators[0] == '/' || cards[1] == 0 || cards[0]%cards[1] != 0) { return; } else { cards[0] /= cards[1]; }
        cards.erase(cards.begin() + 1);
        if (cards[0] <= 24 && cards[0] > answer) { answer = cards[0]; }
    }
    else {
        if (k == 0) {
            for (int i = 0; i <= 2; i++) {
                subsetOrder.push_back(i);
                findOrder(k+1, cards, answer);
                subsetOrder.pop_back();
            }
        }
        if (k == 1) {
            for (int i = 0; i <= 1; i++) {
                subsetOrder.push_back(i);
                findOrder(k+1, cards, answer);
                subsetOrder.pop_back();
            }
        }
    }
}

void findOperators (vector<char> operators, vector<int> cards, int& answer) {
    if (subsetOperators.size() == 3) {
        findOrder(0, cards, answer);
    }
    else {
        for (int i = 0; i < 4; i++) {
            subsetOperators.push_back(operators[i]);
            findOperators(operators, cards, answer);
            subsetOperators.pop_back();
        }
    }
}

void solve() {
    int numberOfHands { 0 };
    cin >> numberOfHands;
    for (int i = 0; i < numberOfHands; i++) {
        vector<int> cards (4);
        cin >> cards[0] >> cards[1] >> cards[2] >> cards[3];
        vector<char> operators {'+', '-', '/', '*'};
        int answer { 0 };
        do {
            findOperators(0, operators, cards, answer);
        } while (next_permutation(cards.begin(), cards.end()));
        cout << answer << "\n";
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}