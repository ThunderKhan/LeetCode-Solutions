#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 200003

typedef struct HashNode {
    long long key;
    int frequency;
    struct HashNode* next;
} HashNode;

typedef struct {
    HashNode* buckets[TABLE_SIZE];
} HashMap;

unsigned int hash(long long key) {
    long long index = key % TABLE_SIZE;

    if (index < 0) {
        index += TABLE_SIZE;
    }

    return (unsigned int)index;
}

void initializeMap(HashMap* map) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        map->buckets[i] = NULL;
    }
}

int getFrequency(HashMap* map, long long key) {
    unsigned int index = hash(key);
    HashNode* current = map->buckets[index];

    while (current != NULL) {
        if (current->key == key) {
            return current->frequency;
        }

        current = current->next;
    }

    return 0;
}

void incrementFrequency(HashMap* map, long long key) {
    unsigned int index = hash(key);
    HashNode* current = map->buckets[index];

    while (current != NULL) {
        if (current->key == key) {
            current->frequency++;
            return;
        }

        current = current->next;
    }

    HashNode* newNode = malloc(sizeof(HashNode));

    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    newNode->key = key;
    newNode->frequency = 1;
    newNode->next = map->buckets[index];

    map->buckets[index] = newNode;
}

void freeMap(HashMap* map) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        HashNode* current = map->buckets[i];

        while (current != NULL) {
            HashNode* nextNode = current->next;
            free(current);
            current = nextNode;
        }
    }
}

int subarraySum(int* nums, int numsSize, int k) {
    HashMap* prefixFrequency = malloc(sizeof(HashMap));

    if (prefixFrequency == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    initializeMap(prefixFrequency);

    incrementFrequency(prefixFrequency, 0);

    long long prefixSum = 0;
    int subarrayCount = 0;

    for (int i = 0; i < numsSize; i++) {
        prefixSum += nums[i];

        long long requiredPrefixSum = prefixSum - k;

        subarrayCount += getFrequency(
            prefixFrequency,
            requiredPrefixSum
        );

        incrementFrequency(prefixFrequency, prefixSum);
    }

    freeMap(prefixFrequency);
    free(prefixFrequency);

    return subarrayCount;
}

int main(void) {
    int nums[] = {1, 1, 1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = 2;

    int result = subarraySum(nums, numsSize, k);

    printf("%d\n", result);

    return 0;
}