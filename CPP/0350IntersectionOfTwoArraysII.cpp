#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2){
    vector<int> large;
    vector<int> small;

    if(nums1.size() > nums2.size()){
        large = nums1;
        small = nums2;
    } else{
        large = nums2;
        small = nums1;
    }

    unordered_map<int, int> frequencyMap;
    for(int num : small){
        frequencyMap[num]++;
    }

    vector<int> result;
    for(int num : large){
        if((frequencyMap.find(num) != frequencyMap.end()) && frequencyMap[num] > 0){
            result.push_back(num);
            frequencyMap[num]--;
        }
    }

    return result;
}

int main(){

    vector<int> nums1 = {4, 9, 4, 9, 8};
    vector<int> nums2 = {9, 9, 4, 6, 7, 4};

    vector<int> result = intersection(nums1, nums2);

    cout << "[";
    for(int i = 0; i < result.size(); i++){
        cout << result[i];
        if(i != result.size() -1){
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}