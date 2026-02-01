public class LC0011ContainerWithMostWater{
    public static void main(String[] args) {
        int[] height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
        int resultArea = maxArea(height);
        String result = String.format(
            "The maximum water that can be held is %d", resultArea
        );
        System.out.println(result);
    }

    public static int maxArea(int[] height){
        int max_area = Integer.MIN_VALUE;
        int n = height.length;

        int left = 0;
        int right = n - 1;

        while(left < right){
            int width = Math.abs(left - right);
            int length = 0;
            if(height[left] < height[right]){
                length = height[left];
            } else{
                length = height[right];
            }
            int currArea = width * length;
            if(currArea > max_area){
                max_area = currArea;
            }

            if(height[left] < height[right]){
                left++;
            } else{
                right--;
            }
        }

        return max_area;
    }
}