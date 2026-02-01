#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(char* s){
    char clean[strlen(s) + 1];
    int j = 0;

    for(int i = 0; s[i] != '\0'; i++){
        if(isalnum((unsigned char) s[i])) {
            clean[j] = tolower((unsigned char) s[i]);
            j++;
        }
    }
    clean[j] = '\0';

    int left = 0;
    int right = strlen(clean) - 1;

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
    
    char s[] = "A man, a plan, a canal: Panama";
    
    if(isPalindrome(s)){
        printf("True");
    } else{
        printf("False");
    }
    
    return 0;
}