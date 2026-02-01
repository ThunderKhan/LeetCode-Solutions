import java.util.List;
import java.util.ArrayList;

public class LC2942FindWordsContainingCharacter{
    public static void main(String[] args){
        String[] words = {"Leet", "code"};
        char x = 'e';

        System.out.println(findWordsContaining(words, x));
    }

    public static List<Integer> findWordsContaining(String[] words, char x){
        List<Integer> ans = new ArrayList<>();
        for(int i = 0; i < words.length; i++){
            if(words[i].indexOf(x) != -1){
                ans.add(i);
            }
        }

        return ans;
    }
}