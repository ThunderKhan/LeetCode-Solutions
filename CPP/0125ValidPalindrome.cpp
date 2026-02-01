#include <iostream>
#include <string>
#include <regex>
#include <algorithm>

using namespace std;

bool isPalindrome(string& s){
    regex pattern("[^a-zA-Z0-9]+");
    string clean = regex_replace(s, pattern, "");

    transform(
        clean.begin(),
        clean.end(),
        clean.begin(),
        [](unsigned char c) {
            return tolower(c);
        }
    );

    int left = 0;
    int right = clean.length() - 1;

    while(left < right){
        if(clean[left] != clean[right]){
            return false;
        }

        left++;
        right--;
    }

    return true;
}

int main(){

    string s = "A man, a plan, a canal: Panama";
    bool result = isPalindrome(s);

    cout << boolalpha << result << endl;

    return 0;
}