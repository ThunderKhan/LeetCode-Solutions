#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2){
    unordered_set<int> seen;
    vector<int> result;

    for(int num : nums1){
        seen.insert(num);
    }

    for(int num : nums2){
        if(seen.count(num)){
            result.push_back(num);
            seen.erase(num);
        }
    }

    return result;
}

void printArray(const vector<int>& arr){
    int n = arr.size();

    cout << "[";
    for(int i = 0; i < n; i++){
        cout << arr[i];
        if(i != n - 1){
            cout << ", ";
        }
    }
    cout << "]\n";
}

int main(){
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};

    vector<int> result = intersection(nums1, nums2);
    printArray(result);
}