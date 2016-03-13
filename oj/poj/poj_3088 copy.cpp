/*
题意：有n个按钮(n <= 11)，每个按钮最多被按一次。一个合法序列是一系列操作，每次可以同时按下一个或多个按钮，问n个按钮有多少合法序列。
如当n = 2，合法序列有：(1), (2), (1)(2), (2)(1), (1, 2), 即5种
*/


/*************************************************************************
    > File Name: poj_3088.cpp
    > Author: james47
    > Mail: 
    > Created Time: Fri Jul 31 19:00:19 2015
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int T, n;
long long f[2049], g[12][2049], ans[12];
void init_0(){		//f[i]表示使用状态i的方案数，状态i是指将i用二进制表示后，为1的位代表选取，为0代表不选取
	f[0] = 1;		//如i = 5 = 101(2进制)，指用1和3所得到的方案数
	for (int i = 1; i < 2048; i++)
		for (int j = i; j; j = (j-1)&i)		//对于状态i，枚举它对应的所有子集j(实际这里子集是i-j，为了写起来方便)
			f[i] += f[i-j];					//对于某个子集的每个合法序列，都可以用子集的补接到序列后
	for (int i = 1; i <= 11; i++){
		ans[i] = 0;
		for (int j = 1; j < (1<<i); j++)	//对于每个数字i，枚举最终使用前i个数中的哪些数字来组成合法序列，累计到答案中
			ans[i] += f[j];
	}
}
void init_1(){
	for (int digit = 1; digit < 12; digit++){
		ans[digit] = 0;
		for (int i = 1; i <= digit; i++){		//对于数字digit，最多有digit个阶段
			for (int j = 1; j < (1<<digit); j++){	//枚举前i个阶段，用了状态j的数
				if (i == 1) g[i][j] = 1;
				else{
					g[i][j] = 0;
					for (int k = (j-1)&j; k; k = (k-1)&j)	//枚举j的子集k，则在阶段i我们用j中剩余的数
						g[i][j] += g[i-1][k];
				}
				ans[digit] += g[i][j];			//对于每个dp[i][j]，都要累计到答案中
			}
		}
	}
}
int main()
{
//	init_0();
	init_1();
	scanf("%d", &T);
	int cas = 0;
	while(T--){
		scanf("%d", &n);
		printf("%d %d %lld\n", ++cas, n, ans[n]);
	}
	return 0;
}
