#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

vector<int> findDisappearedNumber(vector<int>& nums) {
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        int val = abs(nums[i]);
        int idx = val - 1;

        if (nums[idx] > 0) {
            nums[idx] = -nums[idx];
        }
    }
    
    vector<int> missing;
    for (int i = 0; i < n; i++) {
        if (nums[i] > 0) {
            missing.push_back(i + 1);
        }
    }

    return missing;
}