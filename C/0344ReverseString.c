#include <stdio.h>

void reverseString(char* s, int sSize){
    int left = 0;
    int right = sSize - 1;

    while(left <= right){
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;

        left++;
        right--;
    }
}

int main(){

    char s[] = {'h', 'e', 'l', 'l', 'o'};
    int sSize = sizeof(s) / sizeof(s[0]);
    reverseString(s, sSize);

    printf("[");
    for(int i = 0; i < sSize; i++){
        printf("\'");
        printf("%c", s[i]);
        printf("\'");

        if(i != sSize - 1){
            printf(", ");
        }
    }
    printf("]\n");

    return 0;
}