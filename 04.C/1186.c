#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int maximumSum(int* arr, int arrSize) {
    int noDelSum = arr[0];
    int oneDelSum = -10000;
    int result = arr[0];

    for (int i = 1; i < arrSize; i++) {
        int prevNoDel = noDelSum;

        noDelSum = max(
            arr[i],
            noDelSum + arr[i]
        );

        oneDelSum = max(
            prevNoDel,
            arr[i] + oneDelSum
        );

        result = max(
            result,
            max(noDelSum, oneDelSum)
        );
    }

    return result;
}

int main() {
    int arr1[] = {1, -2, 0, 3};
    int arr1Size = sizeof(arr1) / sizeof(arr1[0]);
    int result1 = maximumSum(arr1, arr1Size);
    printf("%d\n", result1);

    int arr2[] = {1, -2, -2, 3};
    int arr2Size = sizeof(arr2) / sizeof(arr2[0]);
    int result2 = maximumSum(arr2, arr2Size);
    printf("%d\n", result2);

    int arr3[] = {-1, -1, -1, -1};
    int arr3Size = sizeof(arr3) / sizeof(arr3[0]);
    int result3 = maximumSum(arr3, arr3Size);
    printf("%d\n", result3);

    return 0;
}