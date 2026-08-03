#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes.
 * Both the returned array and *returnColumnSizes must be malloced.
 */
int** intervalIntersection(
    int** firstList,
    int firstListSize,
    int* firstListColSize,
    int** secondList,
    int secondListSize,
    int* secondListColSize,
    int* returnSize,
    int** returnColumnSizes
) {
    (void)firstListColSize;
    (void)secondListColSize;

    *returnSize = 0;
    *returnColumnSizes = NULL;

    if (firstListSize == 0 || secondListSize == 0) {
        return NULL;
    }

    /*
     * Each loop iteration advances at least one pointer,
     * so firstListSize + secondListSize is a safe capacity.
     */
    int capacity = firstListSize + secondListSize;

    int** result = malloc(capacity * sizeof(*result));
    *returnColumnSizes =
        malloc(capacity * sizeof(**returnColumnSizes));

    int i = 0;
    int j = 0;

    while (i < firstListSize && j < secondListSize) {
        int start1 = firstList[i][0];
        int end1 = firstList[i][1];

        int start2 = secondList[j][0];
        int end2 = secondList[j][1];

        int intersectionStart =
            start1 > start2 ? start1 : start2;

        int intersectionEnd =
            end1 < end2 ? end1 : end2;

        if (intersectionStart <= intersectionEnd) {
            result[*returnSize] =
                malloc(2 * sizeof(*result[*returnSize]));

            result[*returnSize][0] = intersectionStart;
            result[*returnSize][1] = intersectionEnd;

            (*returnColumnSizes)[*returnSize] = 2;
            (*returnSize)++;
        }

        /*
         * The interval that ends first cannot intersect with
         * any later interval from the other list.
         */
        if (end1 <= end2) {
            i++;
        } else {
            j++;
        }
    }

    return result;
}