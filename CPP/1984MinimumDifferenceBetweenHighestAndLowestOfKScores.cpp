#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>

using namespace std;

int minimumDifference(vector<int>& nums, int k) {
    int n = nums.size();

    if (k <= 1 || n == 0) {
        return 0;
    }

    if (k > n) {
        return 0;
    }

    sort(nums.begin(), nums.end());
    int left = 0;
    int right = k - 1;
    int minDiff = numeric_limits<int>::max();

    while (right < n) {
        int currDiff = nums[right] - nums[left];

        if (currDiff < minDiff) {
            minDiff = currDiff;
        }

        left++;
        right++;
    }

    if (minDiff == numeric_limits<int>::max()) {
        return 0;
    }
    return minDiff;
}

struct Test {
    vector<int> nums;
    int k;
    int expected;
    string description;
};

int main() {
    vector<Test> tests = {
        {{90}, 1, 0, "Single element"},
        {{9,4,1,7}, 2, 2, "Example case"},
        {{1,5,9}, 3, 8, "k equals array length"},
        {{5,5,5,5}, 3, 0, "All values equal"},
        {{1,2,3,4,5}, 3, 2, "Already sorted increasing"},
        {{8,1,2,2,3}, 3, 1, "Duplicates present"},
        {{0,0,10,10}, 2, 0, "Zeros included"},
        {{5,100,3}, 1, 0, "k = 1 always zero"},
        {{1,100000,50000,50001}, 2, 1, "Large numeric gap"},
        {{1,2}, 2, 1, "Minimum valid size"},
        {{1,3,6,10,15}, 2, 2, "Increasing gaps"},
        {{4,7,9,1,2}, 4, 6, "Window selection matters"},
        {{5,5,5,5,100}, 4, 0, "Outlier should be ignored"},
        {{10,1,9,2,8,3}, 3, 2, "Alternating values"},
    };

    int passed = 0;

    for (int i = 0; i < tests.size(); i++) {
        try {
            vector<int> nums = tests[i].nums;
            int actual = minimumDifference(nums, tests[i].k);

            if (actual == tests[i].expected) {
                cout << "✅ PASS | Test " << i+1 << ": " << tests[i].description << endl;
                passed++;
            } else {
                cout << "❌ FAIL | Test " << i+1 << ": " << tests[i].description << endl;
                cout << "   Expected: " << tests[i].expected
                     << ", Actual: " << actual << endl;
            }
        } catch (...) {
            cout << "❌ ERROR | Test " << i+1 << ": " << tests[i].description << endl;
        }
    }

    cout << "\nSummary:\n";
    if (passed == tests.size())
        cout << "🎉 All tests passed! (" << passed << "/" << tests.size() << ")\n";
    else
        cout << "⚠️ " << passed << "/" << tests.size() << " tests passed\n";

    return 0;
}
