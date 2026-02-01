#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int minimumOperations(vector<int>& nums) {
    int nonZeroCount = 0;
    unordered_set<int> seen;

    for (int i = 0; i < nums.size(); i++) {
        if ((nums[i] != 0) && (seen.count(nums[i]) == 0)) {
            nonZeroCount++;
            seen.insert(nums[i]);
        }
    }

    return nonZeroCount;
}

int main() {
    vector<int> nums = {1, 5, 0, 3, 5};
    int result = minimumOperations(nums);

    cout << "\nThe minimum number of operations required to make the array zero is ";
    cout << result << endl;
    return 0;
}