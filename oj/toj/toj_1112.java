import java.util.*;
import java.io.*;
import java.math.*;

//public class Main{
class Main{
	public static void main(String[] args){
		Scanner cin = new Scanner(System.in);
		BigInteger ans = BigInteger.valueOf(0);
		BigInteger tmp;
		while(cin.hasNext()){
			tmp = cin.nextBigInteger();
			ans = ans.add(tmp);
			if (tmp.compareTo(BigInteger.ZERO) == 0){
				System.out.println(ans);
				break;
			}
		}
		cin.close();
	}
}
