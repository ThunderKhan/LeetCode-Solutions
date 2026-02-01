#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* defangIPaddr(char* address){
    int dots = 0;
    size_t len = strlen(address);

    for(size_t i = 0; i < len; i++){
        if(address[i] == '.'){
            dots++;
        }
    }

    size_t newLen = len +2 * dots + 1;

    char* ans = malloc(newLen);
    if(!ans) return NULL;

    size_t j = 0;
    for(size_t i = 0; i < len; i++){
        if(address[i] == '.'){
            ans[j++] = '[';
            ans[j++] = '.';
            ans[j++] = ']';
        } else{
            ans[j++] = address[i];
        }
    }

    ans[j] = '\0';

    return ans;
}

int main(){
    char* address = "1.1.1.1";
    printf("%s", defangIPaddr(address));
}