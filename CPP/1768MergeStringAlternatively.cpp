#include <iostream>
#include <string>

using namespace std;

string mergerAlternatively(string& word1, string& word2){
    int len1 = word1.size();
    int len2 = word2.size();

    int i = 0;
    int j = 0;

    string result;
    while((i < len1) && (j < len2)){
        result.push_back(word1[i]);
        i++;

        result.push_back(word2[j]);
        j++;
    }

    while(i < len1){
        result.push_back(word1[i]);
        i++;
    }

    while(j < len2){
        result.push_back(word2[j]);
        j++;
    }

    return result;
}

int main(){

    string word1 = "abc";
    string word2 = "pqr";

    string result = mergerAlternatively(word1, word2);

    cout << result << endl;
    
    return 0;
}