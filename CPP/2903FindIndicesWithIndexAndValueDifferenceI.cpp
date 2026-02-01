#include <iostream>
#include <vector>
#include  <cmath>

using namespace std;

vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference){
    int n = nums.size();
    vector<int> defaultResult = {-1, -1};

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(abs(i - j) >= indexDifference){
                if(abs(nums[i] - nums[j]) >= valueDifference){
                    vector<int> result = {i, j};
                    return result;
                }
            }
        }
    }

    return defaultResult;
}

int main() {

    vector<int> nums = {5, 1, 4, 1};
    int indexDifference = 2;
    int valueDifference = 4;

    vector<int> result = findIndices(nums, indexDifference, valueDifference);
    cout << "[" << result[0] << ", " << result[1] << "]" << endl;
    return 0;
}