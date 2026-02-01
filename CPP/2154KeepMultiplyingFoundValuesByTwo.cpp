#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int findFinalValue(vector<int>& nums, int original){
    unordered_set<int> seen;
    for(int num : nums){
        seen.insert(num);
    }

    while(true){
        if(seen.count(original) == 0){
            break;
        } else{
            original *= 2;
            if(original == 0){
                return 0;
            }
        }
    }

    return original;
}

int main(){

    vector<int> nums = {5, 3, 6, 1, 12};
    int original = 3;

    int result = findFinalValue(nums, original);
    cout << result << endl;
    return 0;
}