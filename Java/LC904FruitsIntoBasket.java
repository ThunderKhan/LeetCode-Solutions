import java.util.HashMap;

public class LC904FruitsIntoBasket {
    public static void main(String[] args) {
        int[] fruits = {1, 2, 3, 2, 2};
        int result = totalFruits(fruits);

        System.out.println("The maximum number of fruits we can pick are " + result);
    }

    public static int totalFruits(int[] fruits) {
        HashMap<Integer, Integer> fruitMap = new HashMap<>();
        int n = fruits.length;
        int low = 0;
        int maxLen = 0;

        for (int high = 0; high < n; high++) {
            if (fruitMap.containsKey(fruits[high])) {
                fruitMap.put(fruits[high], fruitMap.get(fruits[high]) + 1);
            } else {
                fruitMap.put(fruits[high], 1);
            }

            while (fruitMap.size() > 2) {
                fruitMap.put(fruits[low], fruitMap.get(fruits[low]) - 1);
                if (fruitMap.get(fruits[low]) == 0) {
                    fruitMap.remove(fruits[low]);
                }
                low++;
            }
            int length = high - low + 1;
            if (length > maxLen) {
                maxLen = length;
            }
        }

        return maxLen;
    }
}
