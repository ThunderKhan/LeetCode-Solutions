#include <iostream>
#include <string>

using namespace std;

bool isSubsequence(string s, string t){
    int sIdx = 0;
    int tIdx = 0;

    while((sIdx < s.length()) && (tIdx < t.length())){
        if(s[sIdx] == t[tIdx]){
            sIdx++;
        }
        tIdx++;
    }

    return (sIdx == s.length());
}

int main(){
    string s = "abc";
    string t = "ahbgdc";

    bool result = isSubsequence(s, t);
    
    cout << boolalpha;
    cout << result;
}