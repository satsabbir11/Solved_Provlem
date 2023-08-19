import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        while(t-- > 0){
            int m, k, a1, ak, ans =0;
            m = scanner.nextInt();
            k = scanner.nextInt();
            a1 = scanner.nextInt();
            ak = scanner.nextInt();
            
            int needOne = m%k;
            int needK = m/k;
            
            int minOne = Math.min(needOne, a1);
            needOne -= minOne;
            a1 -= minOne;
            
            ak+= a1/k;
            
            int minK  = Math.min(needK, ak);
            needK-=minK;
            
            ans = needOne+needK;
            
            System.out.println(ans);
        }
    }
}