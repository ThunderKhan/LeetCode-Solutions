#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool checkIfExist(vector<int>& arr){
    unordered_set<int> seen;
    for(int num : arr){
        seen.insert(num);
    }

    int zeroCount = 0;
    for(int num : arr){
        if(num == 0){
            zeroCount++;
        }
    }

    for(int num : arr){
        if(num == 0){
            if(zeroCount > 0){
                return true;
            }
        } else{
            if(seen.count(2 * num)){
                return true;
            }
        }
    }

    return false;
}

int main(){

    vector<int> arr = {0, 2, -2};
    bool result = checkIfExist(arr);

    cout << boolalpha << result << endl;
    return 0;
}