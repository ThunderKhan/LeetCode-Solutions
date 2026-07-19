#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int maxProfit(int* prices, int pricesSize) {
    int minPrice = prices[0];
    int bestProfit = 0;

    for (int i = 1; i < pricesSize; i++) {
        minPrice = min(minPrice, prices[i]);
        int profitIfSoldToday = prices[i] - minPrice;

        bestProfit = max(bestProfit, profitIfSoldToday);
    }

    return bestProfit;
}

int main() {
    int prices[] = {7, 1, 5, 3, 6, 4};
    int pricesSize = sizeof(prices) / sizeof(prices[0]);

    int result = maxProfit(prices, pricesSize);
    printf("%d", result);

    return 0;
}