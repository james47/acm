/*
首先预处理dp数组
dp[][]均包含有前缀0的情况
dp[i][0]表示长度为i的数串，含49的个数。
dp[i][1]表示长度为i的数串，不含49，且第一位为9的个数。
dp[i][2]表示长度为i的数串，不含49，且第一位不为9的个数。

递推过程：
对于给定的n，从高位往下枚举。比当前枚举位更高的位我们都取最大值（即n对应位的值）。当前位最大值为x，我们就算填0..x-1的方案，
首先有x*dp[i][0]，即当前位填0..x-1乘以之后位含49的方案。
如果n的当前位大于4，我们可以填4，下一位填9。
如果n的当前位和之前一位组成了49，那么之后0..之后最大值都是含49的，不必再枚举，加上就可以。
当然也有其他递推方法，可能更好理解，大家可以在网上搜搜
*/

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int T;
int a[40];
long long dp[40][3];
long long n;
void init(){
	memset(dp, 0, sizeof(dp));
	dp[0][2] = 1;
	for (int i = 1; i <= 24; i++){						
		dp[i][0] = dp[i-1][0] * 10 + dp[i-1][1];		//i-1长度有49，第i位随便填，或者在i-1且最高位为9的前面补一个4
		dp[i][1] = dp[i-1][1] + dp[i-1][2];				//i-1不含49的两种加起来，都是在前面补9
		dp[i][2] = dp[i-1][1] * 8 + dp[i-1][2] * 9;		//i-1最高位为9时，这位不能填4和9，不为9时，不能填9
	}
}

long long solve(long long n){		//返回小于等于n的数，含49的个数
	int len = 0;
	while(n){						//将数分解为a[len-1]..a[0]
		a[len++] = n % 10;
		n = n / 10;
	}
	long long ans = 0;
	a[len] = 0;
	for (int i = len-1; i+1; i--){	//参见上面分析
		ans = ans + dp[i][0] * a[i];		
		if (a[i] > 4) ans = ans + dp[i][1];
		if (a[i+1] == 4 && a[i] == 9){
			long long tmp = 0;
			for (int j = i-1; j+1; j--)
				tmp = tmp * 10 + a[j];
			ans = ans + tmp + 1;
			break;		//已经有49了，接下来的位不必再枚举
		}
	}
	return ans;
}
int main()
{
	init();
	scanf("%d", &T);
	while(T--)
	{
		scanf("%I64d", &n);
		printf("%I64d\n", solve(n));
	}
	return 0;
}
