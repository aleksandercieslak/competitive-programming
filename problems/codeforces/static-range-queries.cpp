#include <bits/stdc++.h>
using namespace std;

void solve() {
    int numberOfUpdates { 0 };
    int numberOfQueries { 0 };
    cin >> numberOfUpdates >> numberOfQueries;
    vector<int> indices;
    struct Info {
        int left;
        int right;
        int value;
    };
    vector<Info> updates (numberOfUpdates);
    for (int i = 0; i < numberOfUpdates; i++) {
        cin >> updates[i].left >> updates[i].right >> updates[i].value;
        indices.push_back(updates[i].left);
        indices.push_back(updates[i].right);
    }
    vector<Info> queries (numberOfQueries);
    for (int i = 0; i < numberOfQueries; i++) {
        cin >> queries[i].left >> queries[i].right;
        indices.push_back(queries[i].left);
        indices.push_back(queries[i].right);
    }
    sort(indices.begin(), indices.end());
    int q { 1 };
    while (q < static_cast<int>(indices.size())) {
        if (indices[q] == indices[q-1]) {
            indices.erase(indices.begin()+q);
        }
        else { q++; }
    }
    int compressedSize { static_cast<int>(indices.size()) };
    vector<int> difference (compressedSize);
    for (int i = 0; i < numberOfUpdates; i++) {
        auto l { distance(indices.begin(), lower_bound(indices.begin(), indices.end(), updates[i].left)) };
        auto r { distance(indices.begin(), lower_bound(indices.begin(), indices.end(), updates[i].right)) };
        difference[l+1] += updates[i].value;
        difference[r+1] -= updates[i].value;
    }
    for (int i = 0; i < compressedSize; i++) {
        difference[i] += difference[i-1];
    }
    vector<int> prefix (compressedSize);
    for (int i = 1; i < compressedSize; i++) {
        prefix[i] = prefix[i-1] + difference[i] * (indices[i]-indices[i-1]);
    }
    for (int i = 0; i < numberOfQueries; i++) {
        auto l { distance(indices.begin(), lower_bound(indices.begin(), indices.end(), queries[i].left)) };
        auto r { distance(indices.begin(), lower_bound(indices.begin(), indices.end(), queries[i].right)) };
        cout << prefix[r]-prefix[l] << "\n";
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
