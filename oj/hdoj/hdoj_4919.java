import java.util.*;
import java.io.*;
import java.math.*;

public class Main{
	public static BigInteger two = BigInteger.valueOf(2);
	public static HashMap<BigInteger, BigInteger> map = new HashMap<BigInteger, BigInteger>();

	public static BigInteger find(BigInteger k) {
		if (map.containsKey(k)) return map.get(k);
		BigInteger tmp;
		if (k.mod(two).compareTo(BigInteger.ZERO) == 0)
			tmp = find(k.divide(two)).multiply(two).add(find(k.divide(two).subtract(BigInteger.ONE)).multiply(two))
				.add(k.multiply(two)).subtract(BigInteger.valueOf(4));
		else
			tmp = find(k.divide(two)).multiply(BigInteger.valueOf(4)).add(k.divide(two).multiply(BigInteger.valueOf(6)));
		map.put(k, tmp);
		return tmp;
	}

	public static void main(String[] args){
		Scanner cin = new Scanner(System.in);
		map.put(BigInteger.ZERO, BigInteger.ZERO);
		map.put(BigInteger.ONE, BigInteger.ZERO);
		map.put(two, BigInteger.ZERO);
		BigInteger n;
		while (cin.hasNext()){
			n = cin.nextBigInteger();
			BigInteger ans = find(n);
			System.out.println(ans);
		}
		cin.close();
	}
}
