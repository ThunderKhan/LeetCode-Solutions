#include <stdlib.h>

int** insert(
    int** intervals,
    int intervalsSize,
    int* intervalsColSize,
    int* newInterval,
    int newIntervalSize,
    int* returnSize,
    int** returnColumnSizes
) {
    /* At most, the answer can contain intervalsSize + 1 intervals */
    int capacity = intervalsSize + 1;

    int** result = malloc(capacity * sizeof(int*));
    *returnColumnSizes = malloc(capacity * sizeof(int));

    *returnSize = 0;

    int i = 0;
    int newStart = newInterval[0];
    int newEnd = newInterval[1];

    /*
     * Phase 1:
     * Add intervals that come completely before newInterval.
     */
    while (i < intervalsSize && intervals[i][1] < newStart) {
        result[*returnSize] = malloc(2 * sizeof(int));

        result[*returnSize][0] = intervals[i][0];
        result[*returnSize][1] = intervals[i][1];

        (*returnColumnSizes)[*returnSize] = 2;
        (*returnSize)++;

        i++;
    }

    /*
     * Phase 2:
     * Merge all intervals overlapping with newInterval.
     */
    while (i < intervalsSize && intervals[i][0] <= newEnd) {
        if (intervals[i][0] < newStart) {
            newStart = intervals[i][0];
        }

        if (intervals[i][1] > newEnd) {
            newEnd = intervals[i][1];
        }

        i++;
    }

    /* Add the merged new interval */
    result[*returnSize] = malloc(2 * sizeof(int));

    result[*returnSize][0] = newStart;
    result[*returnSize][1] = newEnd;

    (*returnColumnSizes)[*returnSize] = 2;
    (*returnSize)++;

    /*
     * Phase 3:
     * Add the remaining intervals.
     */
    while (i < intervalsSize) {
        result[*returnSize] = malloc(2 * sizeof(int));

        result[*returnSize][0] = intervals[i][0];
        result[*returnSize][1] = intervals[i][1];

        (*returnColumnSizes)[*returnSize] = 2;
        (*returnSize)++;

        i++;
    }

    /*
     * These parameters are required by LeetCode,
     * but their values are not needed here.
     */
    (void)intervalsColSize;
    (void)newIntervalSize;

    return result;
}