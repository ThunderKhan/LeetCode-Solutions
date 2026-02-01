#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* mergeAlternatively(char* word1, char* word2){
    int len1 = strlen(word1);
    int len2 = strlen(word2);

    int i = 0;
    int j = 0;
    int k = 0;

    char* result = (char*) malloc(len1 + len2 + 1);
    if (result == NULL){
        return NULL;
    }

    while((i < len1) && (i < len2)){
        result[k] = word1[i];
        k++;
        i++;

        result[k] = word2[j];
        k++;
        j++;
    }
    while(i < len1){
        result[k] = word1[i];
        k++;
        i++;
    }

    while(i < len2){
        result[k] = word2[j];
        k++;
        j++;
    }

    result[k] = '\0';
    return result;

}

int main(){

    char* word1 = "abc";
    char* word2 = "pqr";

    char* result = mergeAlternatively(word1, word2);

    printf("%s", result);
    free(result);
    return 0;
}