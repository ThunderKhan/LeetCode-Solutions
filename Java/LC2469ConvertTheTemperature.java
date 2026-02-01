import java.util.Arrays;

public class LC2469ConvertTheTemperature{
    public static void main(String[] args){
        double celsius = 36.50;
        System.out.println(Arrays.toString(convertTemperature(celsius)));
    }

    public static double[] convertTemperature(double celsius){
        return new double[] {
            celsius + 273.15,
            celsius * 1.80 + 32.00
        };
    }
}