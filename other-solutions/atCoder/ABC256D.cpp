#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> intervals(n);

    for (int i = 0; i < n; i++) {
        cin >> intervals[i].first >> intervals[i].second;
    }

    sort(intervals.begin(), intervals.end());
    vector<pair<int, int>> result;


    int prevStart = intervals[0].first;
    int prevEnd = intervals[0].second;

    for (int i = 1; i < intervals.size(); i++) {
        int currStart = intervals[i].first;
        int currEnd = intervals[i].second;

        if (currStart <= prevEnd) {
            prevEnd = max(prevEnd, currEnd);
            continue;
        } else {
            result.push_back({prevStart, prevEnd});
            prevStart = currStart;
            prevEnd = currEnd;
        }
    }

    result.push_back({prevStart, prevEnd});

    for (const auto& interval : result) {
        cout << interval.first << ' ' << interval.second << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}