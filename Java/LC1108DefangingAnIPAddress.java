public class LC1108DefangingAnIPAddress{
    public static void main(String[] args){
        String address = "1.1.1.1";
        System.out.println(defangIPaddr(address));
    }

    public static String defangIPaddr(String address){
        StringBuilder sb = new StringBuilder();

        for(char ch : address.toCharArray()){
            if(ch == '.'){
                sb.append("[.]");
            }else{
                sb.append(ch);
            }
        }

        String returnAddress = sb.toString();
        return returnAddress;
    }
}