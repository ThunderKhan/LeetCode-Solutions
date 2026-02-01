#include <stdio.h>
#include <stdbool.h>

bool powerOfThree(int n){
    if(n <= 0){
        return false;
    }

    while(n % 3 == 0){
        n /= 3;
    }

    return n == 1;
}

int main(){
    
    int n = 27;
    printf("%d", powerOfThree(n));
    
    return 0;
}