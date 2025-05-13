import java.util.*;

class Fibonacci{
    public static int fibonacciNumber(int n){
        if(n<=1){
            return n;
        }
        return fibonacciNumber(n-1)+fibonacciNumber(n-2);
    }

    public static void main(String [] args){
        int n;
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number : ");
        n = scanner.nextInt();
        System.out.printf("%dth fibonacci number is : %d",n,fibonacciNumber(n));
        scanner.close();
        return;
    }
}