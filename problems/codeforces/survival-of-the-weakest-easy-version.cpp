#include <bits/stdc++.h>
using namespace std;

void solve() {
    int length { 0 };
    cin >> length;
    vector<long long> numbers;
    vector<long long> vec (length);
    for (long long& a : vec) {
        cin >> a;
    }
    priority_queue<long long, vector<long long>, greater<long long>> p;
    for (int i = 0; i < length-1; i++) {
        for (int j = i+1; j < length; j++) {
            p.push(vec[i] + vec[j]);
        }
    }
    for (int i = 0; i < length-1; i++) {
        numbers.push_back(p.top());
        p.pop();
    }
    while (numbers.size() > 1) {
        priority_queue<array<long long, 3>, vector<array<long long, 3>>, greater<array<long long, 3>>> pq; 
        for (int i = 0; i < static_cast<int>(numbers.size())-1; i++) {
            pq.push({numbers[i] + numbers[i+1], numbers[i], i+1});
        } 
        vector<long long> temp;
        while (temp.size() < numbers.size()-1) {
            temp.push_back(pq.top()[0]);
            if (pq.top()[2] < static_cast<long long>(numbers.size()-1)) {
                pq.push({pq.top()[1] + numbers[pq.top()[2]+1], pq.top()[1], pq.top()[2]+1});
            }
            pq.pop();
        }
        numbers = temp;
    }
    cout << numbers[0]%(1000000000 + 7) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
