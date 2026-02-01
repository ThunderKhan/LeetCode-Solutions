import java.util.HashSet;

public class LC1346CheckIfNAndItsDoubleExist{
    public static void main(String[] args){
        int[] arr = {0, 2, -2};
        System.out.println(checkIfExist(arr));
    }

    public static boolean checkIfExist(int[] arr){
        HashSet<Integer> seen = new HashSet<>();
        for(int num : arr){
            seen.add(num);
        }

        int countZero = 0;
        for(int num : arr){
            if(num == 0){
                countZero++;
            }
        }

        for(int num : arr){
            if(num == 0){
                if(countZero > 1){
                    return true;
                }
            } else{
                if(seen.contains(2 * num)){
                    return true;
                }
            }
        }

        return false;
    }
}