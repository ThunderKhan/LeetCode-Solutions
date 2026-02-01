#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arrayPairSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int result = 0;
    for (int i = 0; i < nums.size(); i += 2) {
        result += nums[i];
    }
    return result;
}

int main() {
    struct Test {
        vector<int> nums;
        int expected;
    };

    vector<Test> tests = {
        {{1,4,3,2}, 4},
        {{6,2,6,5,1,2}, 9},
        {{1,2}, 1},
        {{1,1,1,1}, 2},
        {{-1,-2,-3,-4}, -4},
        {{1,3,2,4}, 4},
        {{1000,-1000,0,0}, 0},
        {{5,5,5,5,5,5}, 15},
        {{1,2,3,4,5,6}, 9},
        {{6,5,4,3,2,1}, 9},
        {{1,2,2,3}, 3},
        {{10,20,30,40,50,60,70,80}, 160},
        {{0,0,0,0,0,0}, 0},
        {{-10,-1,-5,-3}, -8}
    };

    int passed = 0;
    for (int i=0; i<tests.size(); i++) {
        int actual = arrayPairSum(tests[i].nums);
        if (actual == tests[i].expected) {
            cout << "✅ PASS | Test " << i+1 << endl;
            passed++;
        } else {
            cout << "❌ FAIL | Test " << i+1 << endl;
            cout << "   Expected: " << tests[i].expected << ", Actual: " << actual << endl;
        }
    }

    cout << "\nSummary:\n";
    if (passed == tests.size())
        cout << "🎉 All tests passed! (" << passed << "/" << tests.size() << ")\n";
    else
        cout << "⚠️ " << passed << "/" << tests.size() << " tests passed\n";

    return 0;
}