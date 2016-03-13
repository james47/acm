import java.util.*;
import java.math.*;
import java.io.*;

//class Main{
public class Main{
	public static void main(String args[]){
		Scanner cin = new Scanner(System.in);
		while(cin.hasNext()){
			int tot;
			tot = cin.nextInt();
			BigInteger ans = cal(tot);
			System.out.println(ans);
		}
	}
	public static BigInteger cal(int tot){
		BigInteger t1, t2;
		t1 = BigInteger.valueOf(1);
		t2 = BigInteger.valueOf(1);
		int cnt = 2; 
		BigInteger tmp;
		while(cnt < tot){
			tmp = t1;
			t1 = t1.add(t2);
			t2 = tmp;
			cnt ++;
		}
		return t1;
	}
}
