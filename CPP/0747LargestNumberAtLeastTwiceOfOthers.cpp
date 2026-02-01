#include <iostream>
#include <vector>

using namespace std;

int dominantIndex(vector<int>& nums){
    int largest = nums[0];
    int largestIdx = 0;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] > largest){
            largest = nums[i];
            largestIdx = i;
        }
    }

    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == largest){
            continue;
        }

        if((2 * nums[i]) > largest){
            return -1;
        }
    }

    return largestIdx;
}

int main(){

    vector<int> nums = {1, 2, 3, 4};
    int result = dominantIndex(nums);

    cout << result << endl;
    return 0;
}