public class LC2011FindValueOfAVariableAfterPerformingOperations{
    public static void main(String[] args){
        String[] operations = {"--X", "X++", "X++"};
        System.out.println(finalValueAfterOperations(operations));
    }

    public static int finalValueAfterOperations(String[] operations){
        int finalValue = 0;

        for(String operation : operations){
            if(operation == "--X" || operation == "X--"){
                finalValue -= 1;
            } else{
                finalValue += 1;
            }
        }

        return finalValue;
    }
}
