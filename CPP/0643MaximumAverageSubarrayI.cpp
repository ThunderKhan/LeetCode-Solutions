#include <iostream>
#include <vector>

using namespace std;

double findMaxAverage(vector<int>& nums, int k) {
    int n = nums.size();

    if (k > n) {
        return -1.0f;
    }

    int windowSum = 0;
    for (int i = 0; i < k; i++) {
        windowSum += nums[i];
    }

    int maxSum = windowSum;
    for (int i = k; i < n; i++) {
        windowSum += nums[i] - nums[i - k];

        if (windowSum > maxSum) {
            maxSum = windowSum;
        }
    }

    double maxAvg = (double) maxSum / k;
    return maxAvg;
}

int main() {
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;

    double result = findMaxAverage(nums, k);
    cout << "The maximum average for a sub-array of size " << k << " is: " << result << endl;
    return 0;
}