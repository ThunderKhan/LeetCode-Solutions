#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>

using namespace std;

int minPairSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int left = 0;
    int right = nums.size() - 1;
    int maxSum = numeric_limits<int>::min();

    while (left < right) {
        int sum = nums[left] + nums[right];

        if (sum > maxSum) {
            maxSum = sum;
        }

        left++;
        right--;
    }

    return maxSum;
}

struct Test {
    vector<int> nums;
    int expected;
    string description;
};

int main() {
    vector<Test> tests = {
        {{3,5,2,3}, 7, "Given example 1"},
        {{3,5,4,2,4,6}, 8, "Given example 2"},
        {{1,1}, 2, "Minimum size"},
        {{1,100000}, 100001, "Extreme values"},
        {{5,5,5,5}, 10, "All equal"},
        {{1,2,3,4}, 5, "Perfect symmetry"},
        {{1,2,3,100}, 101, "One dominant large"},
        {{10,1,9,2,8,3}, 11, "Random order"},
        {{1,1,1,100,100,100}, 101, "Many duplicates"},
        {{2,2,2,3}, 5, "Unbalanced duplicates"},
        {{7,3,5,1}, 8, "Reverse order"},
        {{1,50,50,50,50,1}, 100, "Heavy middle"},
        {{4,4,4,4,4,4}, 8, "All identical"},
        {{1,2,2,2,9,10}, 11, "Clustered values"},
        {{100000,1,99999,2}, 100001, "Large boundary sums"},
    };

    int passed = 0;

    for (int i = 0; i < tests.size(); i++) {
        auto t = tests[i];
        int actual = minPairSum(t.nums);

        if (actual == t.expected) {
            cout << "✅ PASS | Test " << i+1 << ": " << t.description << endl;
            passed++;
        } else {
            cout << "❌ FAIL | Test " << i+1 << ": " << t.description << endl;
            cout << "   Expected: " << t.expected
                 << ", Actual: " << actual << endl;
        }
    }

    if (passed == tests.size())
        cout << "\n🎉 All tests passed! (" << passed << "/" << tests.size() << ")\n";
    else
        cout << "\n⚠️ " << passed << "/" << tests.size() << " tests passed\n";

    return 0;
}
