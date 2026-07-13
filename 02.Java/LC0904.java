import java.util.HashMap;

public class LC0904 {
    public static void main(String[] args) {
        Solution sol = new Solution();

        int[] fruits = {1, 2, 3, 2, 2};
        int result = sol.totalFruit(fruits);

        System.out.println(result);
    }
}

class Solution {
    public int totalFruit(int[] fruits) {
        int n = fruits.length;
        
        HashMap<Integer, Integer> fruitMap = new HashMap<>();
        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < n; right++) {
            int current = fruits[right];

            if (fruitMap.containsKey(current)) {
                fruitMap.put(current, fruitMap.get(current) + 1);
            } else {
                fruitMap.put(current, 1);
            }

            while (fruitMap.size() > 2) {
                fruitMap.put(fruits[left], fruitMap.get(fruits[left]) - 1);

                if (fruitMap.get(fruits[left]) == 0) {
                    fruitMap.remove(fruits[left]);
                }

                left++;
            }

            int currLen = right - left + 1;
            if (currLen > maxLen) {
                maxLen = currLen;
            }
        }

        return maxLen;
    }
}