#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_set<int> seenWindow;

    for (int i = 0; i < nums.size(); i++) {
        if (seenWindow.count(nums[i])) {
            return true;
        }
        seenWindow.insert(nums[i]);

        if (seenWindow.size() > k) {
            seenWindow.erase(nums[i - k]);
        }
    }

    return false;
}

int main() {
    vector<int> nums = {1, 2, 3, 1};
    int k = 3;

    cout << containsNearbyDuplicate(nums, k) << endl;
    return 0;
}