public class LC1768MergeStringAlternatively{
    public static void main(String[] args){
        String word1 = "abc";
        String word2 = "pqr";

        String result = mergeAlternatively(word1, word2);
        System.out.println(result);
    }

    public static String mergeAlternatively(String word1, String word2){
        int len1 = word1.length();
        int len2 = word2.length();

        int i = 0;
        int j = 0;

        StringBuilder temp = new StringBuilder();
        while((i < len1) && (j < len2)){
            temp.append(word1.charAt(i));
            i++;

            temp.append(word2.charAt(j));
            j++;
        }

        while(i < len1){
            temp.append(word1.charAt(i));
            i++;
        }

        while(j < len2){
            temp.append(word2.charAt(j));
            j++;
        }

        String result = temp.toString();
        return result;
    }
}