public class LC1812DetermineColorOfAChessboardSquare {
    public static void main(String[] args) {

    }

    public static boolean isSquareWhite(String coordinates) {
        return ((coordinates.charAt(0) - 'a' + 1 + coordinates.charAt(1) - '0') % 2 == 1);
    }
}
