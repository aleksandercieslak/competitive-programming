#include <bits/stdc++.h>
using namespace std;

void solve() {
    int numberOfCards { 0 };
    cin >> numberOfCards;
    vector<int> elsieCards (numberOfCards);
    for (auto& a : elsieCards) {
        cin >> a;
    }
    vector<int> original = elsieCards;
    sort(elsieCards.begin(), elsieCards.end());
    vector<int> bessieCards;
    int current { 1 };
    for (int i = 0; i < numberOfCards; i++) {
        while (current < elsieCards[i]) {
            bessieCards.push_back(current);
            current++;
        }
        current++;
    }
    while (current <= numberOfCards) {
        bessieCards.push_back(current);
        current++;
    }
    int answer { 0 };
    vector<int> firstHalf;
    vector<int> secondHalf;
    sort(bessieCards.begin(), bessieCards.end());
    copy(bessieCards.begin(), bessieCards.begin() + numberOfCards/2, back_inserter(firstHalf));
    copy(bessieCards.begin() + numberOfCards/2, bessieCards.end(), back_inserter(secondHalf));
    for (int i = 0; i < numberOfCards/2; i++) {
        auto it { lower_bound(secondHalf.begin(), secondHalf.end(), original[i]) };
        if (it == secondHalf.end()) {
            secondHalf.erase(secondHalf.begin());
        }
        else {
            answer++;
            secondHalf.erase(it);
        }
    }
    for (int i = numberOfCards/2; i < numberOfCards; i++) {
        auto it { lower_bound(firstHalf.begin(), firstHalf.end(), original[i]) };
        if (it == firstHalf.begin()) {
            firstHalf.erase(firstHalf.end()-1);
        }
        else {
            answer++;
            firstHalf.erase(it-1);
        }
    }
    cout << answer << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}