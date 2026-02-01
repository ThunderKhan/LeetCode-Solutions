#include <stdio.h>

int maximumAchievableX(int num, int t){
    return num + 2 * t;
}

int main(){

    int num = 4;
    int t = 1;
    printf("%d", maximumAchievableX(num, t));

    return 0;
}