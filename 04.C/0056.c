#include <stdlib.h>

static int compareIntervals(const void *a, const void *b)
{
    const int *left  = *(const int *const *)a;
    const int *right = *(const int *const *)b;

    if (left[0] < right[0]) return -1;
    if (left[0] > right[0]) return 1;

    if (left[1] < right[1]) return -1;
    if (left[1] > right[1]) return 1;

    return 0;
}

int **merge(
    int **intervals,
    int intervalsSize,
    int *intervalsColSize,
    int *returnSize,
    int **returnColumnSizes
) {
    (void)intervalsColSize;

    *returnSize = 0;
    *returnColumnSizes = NULL;

    if (intervalsSize == 0) {
        return NULL;
    }

    qsort(
        intervals,
        intervalsSize,
        sizeof(int *),
        compareIntervals
    );

    int **result = malloc(intervalsSize * sizeof(int *));
    *returnColumnSizes = malloc(intervalsSize * sizeof(int));

    int previousStart = intervals[0][0];
    int previousEnd = intervals[0][1];

    for (int i = 1; i < intervalsSize; i++) {
        int currentStart = intervals[i][0];
        int currentEnd = intervals[i][1];

        if (currentStart <= previousEnd) {
            if (currentEnd > previousEnd) {
                previousEnd = currentEnd;
            }
        } else {
            result[*returnSize] = malloc(2 * sizeof(int));
            result[*returnSize][0] = previousStart;
            result[*returnSize][1] = previousEnd;

            (*returnColumnSizes)[*returnSize] = 2;
            (*returnSize)++;

            previousStart = currentStart;
            previousEnd = currentEnd;
        }
    }

    result[*returnSize] = malloc(2 * sizeof(int));
    result[*returnSize][0] = previousStart;
    result[*returnSize][1] = previousEnd;

    (*returnColumnSizes)[*returnSize] = 2;
    (*returnSize)++;

    return result;
}