#include <stdio.h>
#include <string.h>

bool isSubsquence(char* s, char* t){
    int sIdx = 0;
    int tIdx = 0;

    size_t lenS = strlen(s);
    size_t lenT = strlen(t);

    while((sIdx < lenS) && (tIdx < lenT)){
        if(s[sIdx] == t[tIdx]){
            sIdx++;
        }
        tIdx++;
    }
    return (sIdx == lenS);
}

void printBool(int bin){
    if(bin == 0){
        printf("false");
    } else{
        printf("true");
    }
}

int main(){

    char s[] = "abc";
    char t[] = "ahbgdc";

    printBool(isSubsquence(s, t));
}