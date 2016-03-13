import java.math.*;
import java.util.*;

class Main{
	public static void main(String args[]){
		Scanner cin = new Scanner(System.in);
		BigDecimal Eight = new BigDecimal(8);
		while(cin.hasNext()){
			String num;
			num = cin.nextLine();
			BigDecimal ans = new BigDecimal(0);
			BigDecimal tmp = new BigDecimal(1);
			for(int i = 2;i < num.length();++i){
				tmp = tmp.divide(Eight);
				ans = ans.add(new BigDecimal(num.charAt(i) - '0').multiply(tmp));
			}
			System.out.println(num + " [8] = " + ans + " [10]");
		}
	}
}
