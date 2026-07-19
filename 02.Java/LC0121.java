public class LC0121 {
    public static void main(String[] args) {
        Solution sol = new Solution();

        int prices[] = {7, 1, 5, 3, 6, 4};
        int result = sol.maxProfit(prices);

        System.out.println(result);
    }
}

class Solution {
    public int maxProfit(int[] prices) {
        int minPrice = prices[0];
        int bestProfit = 0;

        for (int price : prices) {
            minPrice = Math.min(minPrice, price);
            int profitIfSoldToday = price - minPrice;

            bestProfit = Math.max(bestProfit, profitIfSoldToday);
        }

        return bestProfit;
    }
}