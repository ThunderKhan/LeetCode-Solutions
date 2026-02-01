import java.util.HashSet;
import java.util.ArrayList;

public class LC3668RestoreFinishingOrder{
    public static void main(String[] args) {
        int[] order = {3, 1, 2, 5, 4};
        int[] friends = {1, 3, 4};

        int[] result = recoverOrder(order, friends);

        for(int x : result){
            System.out.print(x + " ");
        }
    }

    public static int[] recoverOrder(int[] order, int[] friends){
        HashSet<Integer> setFriends = new HashSet<>();
        
        for(int friend : friends){
            setFriends.add(friend);
        }

        ArrayList<Integer> temp = new ArrayList<>();

        for(int participant : order){
            if(setFriends.contains(participant)){
                temp.add(participant);
            }
        }

        int ans[] = new int[temp.size()];
        for(int i = 0; i < temp.size(); i++){
            ans[i] = temp.get(i);
        }

        return ans;
    }
}