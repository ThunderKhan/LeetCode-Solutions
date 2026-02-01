#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    vector<vector<int>> result;

    int minDiff = numeric_limits<int>::max();
    for (int i = 0; i < (n - 1); i++) {
        int currDiff = arr[i + 1] - arr[i];
        vector<int> pair;
        
        if (currDiff < minDiff) {
            minDiff = currDiff;
            result.clear();

            pair.push_back(arr[i]);
            pair.push_back(arr[i + 1]);

            result.push_back(pair);
        } else if (currDiff == minDiff) {
            pair.push_back(arr[i]);
            pair.push_back(arr[i + 1]);

            result.push_back(pair);
        }
    }

    return result;
}

int main() {
    vector<int> arr = {4, 2, 1, 3};
    vector<vector<int>> result = minimumAbsDifference(arr);

    for (auto &pair : result) {
        cout << "[ ";
        for (int x : pair) {
            cout << x << " ";
        }
        cout << "]";
    }
    cout << endl;

    return 0;
}